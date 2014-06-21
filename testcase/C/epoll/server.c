#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXLINE 5
#define LISTENQ 20

void
setnonblocking(int sock)
{
    int opts;

    opts = fcntl(sock, F_GETFL);
    if (opts < 0) {
        printf("fcntl F_GETFL error! \n");
        return ; 
    }

    if ( fcntl(sock, F_SETFL, opts | O_NONBLOCK) < 0) {
        printf("fcntl F_SETFL error! \n");
        return ; 
    } 
}

void
CloseAndDisable(int sockid, struct epoll_event ee)
{
    close(sockid);
    ee.data.fd = -1;
}


int main(int argc, const char *argv[])
{
    int i;
    int listenfd,connfd;
    int sockfd, epfd;
    int nfds, portnumber;
    char line[MAXLINE] = {0};

    struct epoll_event ev;
    struct epoll_event events[20];

    socklen_t clilen;
    struct sockaddr_in clientaddr;
    struct sockaddr_in serveraddr;


    portnumber = 5000;

    epfd = epoll_create(256);
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    inet_aton("127.0.0.1",&(serveraddr.sin_addr));
    serveraddr.sin_port = htons(portnumber);


    bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    listen(listenfd, LISTENQ);

    ev.data.fd = listenfd;
    ev.events = EPOLLIN | EPOLLET;

    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

    for (; ;) {
        nfds = epoll_wait(epfd, events, 20, 500);
        printf("epoll_wait return \n");

        for (i = 0; i < nfds; i++) {
            if(events[i].data.fd == listenfd) {
                connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clilen);
                if (connfd < 0) {
                    printf("accept <0 \n");
                    return 1;
                }

                char *str = inet_ntoa(clientaddr.sin_addr);
                printf("accept a connection from %s \n", str);
                setnonblocking(connfd);
                ev.data.fd = connfd;
                ev.events = EPOLLIN | EPOLLET;

                epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);
            } else if ( events[i].events & EPOLLIN) {
                printf("epoll in \n");

                if ( (sockfd = events[i].data.fd) < 0 )
                    continue;


                char *head = line;
                int recvNum = 0;
                int count = 0;
                int bReadOk = 0;

                while (1) {
                    recvNum = recv(sockfd, head + count, MAXLINE, 0);
                    if (recvNum < 0)  {
                        if ( errno == EAGAIN ) {
                            /*
                             * 由于是非阻塞的模式,所以当errno为EAGAIN时
                             * 表示当前缓冲区已无数据可读
                             * 
                             * */
                            bReadOk = 1;
                            break; 
                        } else if (errno == ECONNRESET) {
                            CloseAndDisable(sockfd, events[i]);
                            printf("counterpart send out rst \n");
                            break;
                        } else if (errno == EINTR) {
                            /* 被信号中断 */
                            continue; 
                        } else {
                            CloseAndDisable(sockfd, events[i]);
                            printf("unrecovable error \n");
                            break; 
                        } 
                    } else if (0 == recvNum) {
                        CloseAndDisable(sockfd, events[i]);
                        printf("counterpart has shut off\n");
                        break; 
                    } 

                    /*recvNum > 0*/
                    count += recvNum;
                    if (MAXLINE == recvNum) {
                        continue; 
                    } else {
                        bReadOk = 1;
                        break; 
                    }
                }/*--end--while--*/ 

                if (1 == bReadOk) {
                    line[count] = '\0';
                    printf("we have read from the client :%s\n", line);

                    ev.data.fd = sockfd;
                    ev.events = EPOLLOUT | EPOLLET;
                    epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev); 
                }
            } else if (events[i].events & EPOLLOUT) {
                /* const char str[] = "hello from epoll : this is a long string which may be cut by the net\n"; */
                const char str[] = "123\n";
                memcpy(line, str, sizeof(str));
                printf("write line: %s\n", line);
                sockfd = events[i].data.fd;

                int bWritten = 0;
                int writenLen = 0;
                int count = 0;
                char * head = line;
                while(1)
                {
                    // 确保sockfd是非阻塞的
                    writenLen = send(sockfd, head + count, MAXLINE, 0);
                    if (writenLen == -1)
                    {
                        if (errno == EAGAIN) {
                            // 对于nonblocking 的socket而言，这里说明了已经全部发送成功了
                            bWritten = 1;
                            break;
                        } else if(errno == ECONNRESET) {
                            // 对端重置,对方发送了RST
                            CloseAndDisable(sockfd, events[i]);
                            printf("counterpart send out RST\n");
                            break;
                        } else if (errno == EINTR) {
                            // 被信号中断
                            continue;
                        } else
                        {
                            // 其他错误
                        }
                    }

                    if (writenLen == 0) {
                        // 这里表示对端的socket已正常关闭.
                        CloseAndDisable(sockfd, events[i]);
                        printf("counterpart has shut off\n");
                        break;
                    }

                    // 以下的情况是writenLen > 0
                    count += writenLen;
                    if (writenLen == MAXLINE) {
                        // 可能还没有写完
                        continue;
                    } else {// 0 < writenLen < MAXLINE
                        // 已经写完了
                        bWritten = 1;
                        break; // 退出while(1)
                    }
                }

                if (bWritten == 1) {
                    //设置用于读操作的文件描述符
                    ev.data.fd=sockfd;

                    //设置用于注测的读操作事件
                    ev.events=EPOLLIN | EPOLLET;

                    epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
                }
            }
        }

    }/*--end--inner for loop--*/

    return 0;
}/* --end main -- */


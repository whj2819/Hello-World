#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, const char *argv[])
{
    struct sockaddr_in servaddr;
    int listenfd, connfd;
    int n = 0;
    int i = 0;
    int iRet = 0;
    int nfds;
    char msg[128] = {0};
    int epfd;
    struct epoll_event ev, events[20];


    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        printf("create socket error \n");
        exit(0); 
    }


    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    listen(listenfd, 128);

    epfd = epoll_create(20);
    if (-1 == epfd)
    {
        printf("epoll create error \n");
        exit(0); 
    }

    ev.data.fd = listenfd;
    ev.events = EPOLLIN | EPOLLET;
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

    while(1) {
        nfds = epoll_wait(epfd, events, 20, 10000);
        for (i = 0; i < nfds; i++) {
            if (events[i].data.fd == listenfd) {
                connfd  = accept(listenfd, NULL, NULL);
                if (connfd < 0) {
                    printf("connfd error \n");
                    exit(0);
                } else {
                    printf("connfd ok\n"); 
                }

                ev.data.fd = connfd;
                ev.events = EPOLLIN | EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);
            } else if (events[i].events & EPOLLIN) {
                n = read(connfd, msg, 128);
                if (n < 0) {
                    printf("str_echo:read error\n");
                }
                printf("msg: %s \n", msg);
                ev.data.ptr = "hello";
                ev.events = EPOLLOUT | EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_MOD, connfd, &ev);
            } else if (events[i].events & EPOLLOUT) {
                printf("write write \n");

            }
        } 
    }


    return 0;
}

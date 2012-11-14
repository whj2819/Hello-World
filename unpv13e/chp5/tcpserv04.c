#include "unp.h"

void sig_chld(int);

int
main(int argc,char **argv)
{
    int listenfd,connfd;
    pid_t  childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr,servaddr;

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd,(SA*)&servaddr,sizeof(servaddr));

    listen(listenfd,LISTENQ);
    
    Signal(SIGCHLD,sig_chld);

    for (; ;) {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd,(SA*)&clilen,&clilen)) < 0) {
            if (errno == EINTR) 
                continue;
            else 
                err_sys("accept error \n");
        }

        if ((childpid = fork() ) == 0) {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        Close(connfd);
    }

    return 0;
}

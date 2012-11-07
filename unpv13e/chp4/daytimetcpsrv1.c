#include "unp.h"
#include <time.h>

int
main(int argc,char **argv)
{
    int    listenfd,connfd;
    socklen_t len;
    struct sockaddr_in servaddr,cliaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13); /* daytime server */

    bind(listenfd,(SA *)&servaddr,sizeof(servaddr));

    listen(listenfd,LISTENQ);

    for (;;) {
        len = sizeof(cliaddr);
        connfd = accept(listenfd,(SA*)&cliaddr,&len);
        printf("connection from %s,port %d\n",
                inet_ntop(AF_INET,&cliaddr.sin_addr,buff,sizeof(buff)),
                ntohs(cliaddr.sin_port));

        ticks = time(NULL);
        snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
        write(connfd,buff,strlen(buff));

        close(connfd);
    }

    return 0;
}

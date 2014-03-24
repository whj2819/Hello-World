#include "unp.h"

void
str_cli(FILE *fp,int sockfd)
{
    char    sendline[MAXLINE],revline[MAXLINE];

    while (fgets(sendline,MAXLINE,fp) != NULL) {
        writen(sockfd,sendline,strlen(sendline));
        sleep(1);
        writen(sockfd,sendline + 1,strlen(sendline) - 1);

        if (readline(sockfd,revline,MAXLINE) == 0) {
            printf("str_cli:server terminated prematurely \n");
            exit (0);
        }

        fputs(revline,stdout);

    }
}

#include "unp.h"

void
str_cli(FILE *fp,int sockfd)
{
    char    sendline[MAXLINE],revline[MAXLINE];

    while (fgets(sendline,MAXLINE,fp) != NULL) {
        writen(sockfd,sendline,strlen(sendline));

        if (readline(sockfd,revline,MAXLINE) == 0) {
            printf("str_cli:server terminated prematurely \n");
            exit (0);
        }

        fputs(revline,stdout);

    }
}

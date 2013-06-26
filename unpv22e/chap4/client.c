#include "unpipc.h"

void
client(int readfd, int writefd)
{
    size_t len;
    ssizet_ n;
    char buff[MAXLINE];

    Fgets(buff,MAXLINE,stdin);
    len = strlen(buff);
    if (buff[len - 1] == '\n')
        len--;

    Write(writefd,buff,len);

    while ( (n = Read(readfd,buff,MAXLINE)) > 0)
        Write(writefd,buff,n);

}

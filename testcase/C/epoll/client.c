#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, const char *argv[])
{
    struct sockaddr_in servaddr;
    int sockfd;
    int iRet = 0;
    char msg[128] = "hello world";


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("create socket error \n");
        exit(0); 
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    iRet = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (iRet < 0) {
        printf("connect error \n");
        exit (0); 
    }

    printf("send message to server\n");
    write(sockfd, msg, sizeof(msg));

    return 0;
}

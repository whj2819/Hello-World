#include "unp.h"

int
main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2) {
        printf("usage:tcpcli <IPaddress> \n");
        exit(0); 
    }

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr) );

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd, (SA*)&servaddr, sizeof(servaddr) );

    printf("stdin = %d, sockfd = %d \n", fileno(stdin), sockfd);
    str_cli(stdin, sockfd);

    exit(0); 
}
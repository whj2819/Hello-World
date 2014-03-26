#include "unp.h"

int
main(int argc, char **argv)
{
    int fd;

    if (argc != 4)
        err_quit("openfile <sockfd#> <filename> <mode>");

    printf("argv[0]:%s argv[1]:%s \n", argv[0], argv[1]);

    printf("argv[2]:%s argv[3]:%d \n", argv[2], atoi(argv[3]));
    if ( (fd = open(argv[2], atoi(argv[3]))) < 0)
        exit( (errno>0) ? errno:255);

    printf("........................\n");

    if ( write_fd(atoi(argv[1]), "", 1, fd) < 0  )
        exit( (errno>0) ? errno:255);

    exit(0);
}

#include "unp.h"


int
my_open(const char *pathname, int mode)
{
    int fd, sockfd[2], status;
    pid_t childpid;
    char c, argsockfd[10], argmode[10];

    Socketpair(AF_LOCAL, SOCK_STREAM, 0, sockfd);
    printf("pathname:%s \n", pathname);

    if ( (childpid = Fork()) ==  0) {
        Close(sockfd[0]);
        snprintf(argsockfd, sizeof(argsockfd), "%d", sockfd[1]);
        snprintf(argmode, sizeof(argmode), "%d", mode);
        execl( "./openfile", "openfile", argsockfd, pathname, argmode,
                (char *)NULL );
        err_sys("execl error"); 
    }
    Close(sockfd[1]);

    Waitpid(childpid, &status, 0);
    if (WIFEXITED(status) == 0)
        err_quit("child did not terminate");

    if ( (status == WEXITSTATUS(status)) == 0) {
        Read_fd(sockfd[0], &c, 1, &fd); 
        printf("recvfd = %d \n", fd);
    } else {
        errno = status;
        fd = -1; 
    }

    Close(sockfd[0]);
    return fd;
}

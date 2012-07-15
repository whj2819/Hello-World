#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    pid_t   pid;
    int status;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    }else if( 0 == pid) {
        exit(7);
    }

    if ( wait(&status) ) {
        err_sys("wait error");
    }
    pr_exit(status);


    if ((pid = fork()) < 0) {
        err_sys("fork error");
    }else if( 0 == pid) {
        abort(); 
    }

    if ( wait(&status) ) {
        err_sys("wait error");
    }
    pr_exit(status);

        
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    }else if( 0 == pid) {
        status /= 0; 
    }

    if ( wait(&status) ) {
        err_sys("wait error");
    }
    pr_exit(status);

    exit(0);
}

#include "apue.h"
#include <sys/wait.h>

void pr_exit(int status)
{
    if ( WIFEXITED(status) ) {
        printf( "normal termination,exit status = %d \n",WEXITSTATUS(status) );
    } else if ( WIFSIGNALED(status) ) {
        printf( "abnormal termination,signal number = %d%s \n",WTERMSIG(status),
#ifdef WCOREDUMP
                WCOREDUMP(status) ? "(core file generated)" : "" );
#else
        "");
#endif
    } else if ( WIFSTOPPED(status) ) {
        printf("child stopped,signal number = %d \n", WSTOPSIG(status) );
    }
}

extern int system(const char *cmdstring);

int main(void)
{
    int status;

    if ((status = system("date")) < 0) {
        err_sys("system() error.\n");
    }
    pr_exit(status);

    if ((status = system("nosuchcommand")) < 0) {
        err_sys("system() error.\n");
    }
    pr_exit(status);

    if ((status = system("who; exit 44")) < 0) {
        err_sys("system() error.\n");
    }
    pr_exit(status);

    exit (0);
}

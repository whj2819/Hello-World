#include "apue.h"
#include <stdlib.h>
#include <errno.h>




void pr_mask(const char *str)
{
    sigset_t sigset;
    int errno_save;

    errno_save = errno;
    if (sigprocmask(0,NULL,&sigset) < 0)
        err_sys("sigprocmask error");

    printf("%s",str);

    if (sigismember(&sigset, SIGINT)) err_sys("SIGINT ");
    if (sigismember(&sigset, SIGQUIT)) err_sys("SIGQUIT ");
    if (sigismember(&sigset, SIGUSR1)) err_sys("SIGUSR1 ");
    if (sigismember(&sigset, SIGALRM)) err_sys("SIGALRM ");

    /* remaining signals can go here */

    printf("\n");
    errno = errno_save;
}

static void
sig_int(int signo)
{
    pr_mask("\n in sig_int :\n");
}

int
main(void)
{
    sigset_t newmask, oldmask, waitmask;

    pr_mask("program start:");

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("sig sigint error");

    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if ( sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("sig block error ");

    pr_mask("in critical region ");

    if (sigsuspend(&waitmask) != -1)
        err_sys("sigsuspend error");

    pr_mask("after return from sigsuspend");


    if ( sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys(" sig_setmask error ");


    pr_mask("program exit :");
    exit(0);
}



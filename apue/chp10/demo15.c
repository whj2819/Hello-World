#include "apue.h"

static void sig_int(int);

int
main(void)
{
    sigset_t newmask, oldmask, waitmask;

    pr_mask("program start:");

    if (signal(SIGINT, sig_int) == SIG_ERR)
        printf("sig sigint error\n");

    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if ( sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        printf("sig block error \n");

    pr_mask("in critical region ");


    if ( sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        printf(" sig_setmask error \n");


    pr_mask("program exit");

    return 0;
}

static void
sig_int(int signo)
{
    pr_mask("\n in sig_int \n");
}

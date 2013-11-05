#include "apue.h"


static void
sig_quit(int signo)
{
    printf("caught SIGQUIT\n");

    if(signal(SIGQUIT, SIG_DFL) == SIG_ERR)
        err_sys("can't reset SIGQUIT"); 
}

int
main(void)
{
    sigset_t newmask, oldmask, pendmask;

    if (signal(SIGQUIT, sig_quit) == SIG_ERR)
        err_sys("can't reset SIGQUIT"); 

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");

    sleep(5);

    if (sigpending(&pendmask) < 0)
        err_sys("sigpending error");

    if (sigismember(&pendmask, SIGQUIT))
        printf("SIGQUIT pending \n");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");
    printf("sigquit unblock \n");

    sleep(5);
    exit (0);
}

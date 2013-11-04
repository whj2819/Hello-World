#include "apue.h"

static void sig_usr(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1 \n");
    else
        err_dump("received signal %d \n", signo);

}


int
main(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        err_sys("can't catch SIGUSR1");

   for (; ;)
       pause();

}

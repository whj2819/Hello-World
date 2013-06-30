#include <stdio.h>
#include <signal.h>


int
main(int argc, char *argv[])
{
    sigset_t newmask ,oldmask;


    sigemptyset(&newmask);
    sigaddset(&newmask,SIGINT);


    if( sigismember(&newmask,SIGINT))
        printf("newmask SIGINT \n");

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        printf("error ------------\n");

    printf("===========================before \n");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        printf("error ------------\n");






    printf("===========================after\n");
    if( sigismember(&oldmask,SIGINT))
        printf("oldmask SIGINT \n");

    return 0;
}

#include <signal.h>
#include <unistd.h>

static void 
sig_alrm(int signo)
{
    /*nothing to do,just return to wake up the pause */
}

unsigned int 
sleep1(unsigned int nsecs)
{
    if (signal(SIGALRM,sig_alrm) == SIG_ERR) {
        return (nsecs);
    }

    alarm(nsecs);
    pause();
    return(alarm(0));
}

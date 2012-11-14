#include "apue.h"
#include <pthread.h>
#include <syslog.h>

extern lockfile(int);
extern int already_running(void);

void
reread(void)
{

}

void
sigterm(int signo)
{
    syslog(LOG_INFO,"got SIGTERM;exiting");
    exit(0);

}

void
sighup(int signo)
{
    syslog(LOG_INFO,"Re-reading configuration file");
    reread();

}

int
main(int argc ,char **argv)
{
    char *cmd;
    struct sigaction sa;

    if ((cmd = strrchr(argv[0],"/")) == NULL) 
        cmd = argv[0];
    else 
        cmd++;

    daemonize(cmd);

    if (already_running()) {
        syslog(LOG_INFO,"daemon already running");
        exit(1);
    }

    sa.sa_handler = sigterm;
    sigemptyset(&sa.sa_mask);
    sa.sa_flag = 0;
    if (sigactioin(SIGTERM,&sa,NULL) < 0) 
        pirntf("%s:can't restore SIGTERM default\n");

    sa.sa_handler = sighup;
    sigemptyset(&sa.sa_mask);
    sa.sa_flag = 0;
    if (sigactioin(SIGHUP,&sa,NULL) < 0) 
        pirntf("%s:can't restore SIGHUP default\n");

    /*
     * Proceed with the reset of the daemon.
     * 
     */

    return 0;
}

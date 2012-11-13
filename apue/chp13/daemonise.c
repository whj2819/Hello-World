#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>


void
daemonize(const char *cmd)
{
    int i,fd0,fd1,fd2;
    pid_t pid;
    struct rlimit rl;
    struct sigaction;

    umask(0);

    if (getrlimit(RLIMIT_NOFILE,&rl) < 0) {
        printf("%s:can't get file limit\n",cmd);
        exit(0);
    }

    if ((pid = fork()) < 0) 
        printf("%s:can't fork",cmd);
    else if (pid != 0)
         exit(0);
    setsid();

    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGHUP,&sa,NULL) < 0) {
        printf("%s:can't ignore SIGHUP\n");
    }

    if ((pid = fork()) < 0) 
        printf("%s:can't fork\n",cmd);
    else if (pid != 0) 
        exit(0);
}

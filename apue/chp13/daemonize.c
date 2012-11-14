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
    struct sigaction sa;

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

    if (chdir("/") < 0)
        printf("%s can't change Directory to / \n");

    if (rl.rlim_max == RLIM_INFINITY)
        rl.rlim_max = 1024;

    for (i = 0;i < rl.rlim_max;i++) 
        close (i);

    fd0 = open("/dev/null",O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    openlog(cmd,LOG_CONS,LOG_DAEMON);
    if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
        syslog(LOG_ERR,"unexpected file descriptors %d %d %d",
                fd0,fd1,fd2);
        exit(1);
    }
}

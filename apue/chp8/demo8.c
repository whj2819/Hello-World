#include "apue.h"
#include <sys/wait.h>

char *env_init[] = { "USER=unknown","PATH=/tmp",NULL };

int main(void)
{
    pid_t pid;

    if ( (pid = fork()) < 0 ) {
        err_sys("fork error.");
    } else if ( 0 == pid ) {
        if ( execle("echoall","alex","myarg1",
                    "MY ARG2",(char*)0,env_init) < 0) {
            err_sys("ececle error.");
        }
    }

    if (waitpid(pid,NULL,0) < 0) {
        err_sys("wait error.");
    }

    printf("\n");
    if ( (pid = fork()) < 0 ) {
        err_sys("fork error.");
    } else if ( 0 == pid ) {
        if ( execlp("./echoall","echoall","only one arg", (char*)0) < 0) {
            err_sys("ececlp error.");
        }
    }

    exit (0);
}

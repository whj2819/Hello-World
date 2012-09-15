#include "apue.h"

static void charatatime(char *);

int main(void)
{
    pid_t   pid;

    TELL_WAIT();

    if ((pid = fork()) < 0) {
        err_sys("fork error!");
    } else if ( 0 == pid ) {
        charatatime("output from chile \n");
        WAIT_PARTENT();
    } else {
        charatatime("output from partent \n");
        TELL_CHILD(pid);
    }

    exit(0);
}


static void charatatime(char *str)
{
    char *ptr;
    int c;
    
    setbuf(stdout,NULL);

    for (ptr = str;(c = *ptr++) != 0;) {
        putc(c,stdout);
    }
}

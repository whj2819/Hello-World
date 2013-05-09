#include "apue.h"



int glob = 6;
char buf[] = "a write to stdout \n";

int main(void)
{
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO,buf,sizeof(buf) - 1) != sizeof(buf) -1) {
        err_sys("write error");
    }
    
    printf("before fork \n");
    if (( pid = fork()) < 0) {
        err_sys("fork error \n");
    } else if( 0 == pid ) { /*child */
        glob++;
        var++;
        //printf("I'm child process!\n");
       // printf("pid = %d ppid= %d \n",getpid(),getppid());
    } else {
        //printf("I'm partent process!\n");
        sleep(2);
    }
    printf("pid = %d glob = %d var = %d \n",getpid(),glob,var);

    exit(0);
}


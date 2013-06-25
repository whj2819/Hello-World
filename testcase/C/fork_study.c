#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>




int
main(int argc, char *argv[])
{
    int i;


    //setbuf(stdout,NULL);
    for (i=0; i<2; i++) {
        fork();
        printf("ppid = %d,pid = %d, i=%d \n",getppid(),getpid(),i);
        printf("H");
    }
    sleep(10);
    
    return 0;
}

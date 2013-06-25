#include <stdio.h>

#define SEM_NAME "/tmp/mysem"


int
main(int argc, char *argv[])
{
    int fd,i,nloop,zero = 0;
    int *ptr;
    sem_t *mutex;

    if (argc != 3) {
        printf("usage: incr2 <pathname> <#loops> \n");
        return -1;
    }
    nloop = atoi(argv[2]);

    fd = open(argv[1],O_RDRW | O_CREAT,00666);
    write(fd, &zeor,sizeof(int));
    ptr = (int *)mmap(
                      NULL,
                      sizeof(int),
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED,
                      fd,
                      0
                    );

    close(fd);

    mutex =sem_open(SEM_NAME,O_CREAT | O_EXCL,00666,1);
    sem_link(SEM_NAME);

    setbuf(stdout,NULL);

    if (fork() == 0) {

    }


    

    return 0;
}

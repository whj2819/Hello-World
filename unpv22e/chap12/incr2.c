#include "unpipc.h"

#define SEM_NAME "mysem"


int
main(int argc, char *argv[])
{
    int fd,i,nloop,zero = 0;
    int *ptr;
    sem_t *mutex;

    if (argc != 3) {
        err_quit("usage: incr2 <pathname> <#loops> \n");
        return -1;
    }
    nloop = atoi(argv[2]);

    fd = Open(argv[1],O_RDWR | O_CREAT,00666);
    Write(fd, &zero,sizeof(int));
    ptr = (int *)Mmap(
                      NULL,
                      sizeof(int),
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED,
                      fd,
                      0
                    );

    close(fd);

    mutex =Sem_open(SEM_NAME,O_CREAT | O_EXCL,00666,1);
    Sem_unlink(SEM_NAME);

    setbuf(stdout,NULL);

    if (fork() == 0) {

    }

    return 0;
}

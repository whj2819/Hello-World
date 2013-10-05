#include "unpipc.h"


struct shmstruct {
    int count;
};

sem_t    *mutex;

int
main(int argc, char **argv)
{

    int fd;
    struct shmstruct *ptr;

    if (argc != 3)
        err_quit("usage: server1 <shmname> <semname>");

    shm_unlink(Px_ipc_name(argv[1]));
    fd = shm_open(Px_ipc_name(argv[1]), O_RDWR | O_CREAT | O_EXCL, FILE_MODE);
    Ftruncate(fd, sizeof(struct shmstruct));
    ptr = Mmap(
                  NULL
                , sizeof(struct shmstruct)
                , PROT_READ | PROT_WRITE
                , MAP_SHARED
                , fd
                , 0
            );
    Close(fd);

    sem_unlink(Px_ipc_name(argv[2]));
    mutex = sem_open(Px_ipc_name(argv[2]), O_CREAT | O_EXCL, FILE_MODE, 1);
    Sem_close(mutex);
    
    exit(0);
}

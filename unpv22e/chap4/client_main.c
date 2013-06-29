#include "fifo.h"
#include <unistd.h>


void client(int,int);

int
main(int argc, char *argv[])
{

    int readfd,writefd;


    if ((mkfifo(FIFO1, FILE_MODE) < 0) && (errno != EEXIST) )
        err_sys("can't create %s",FIFO1);
    if ((mkfifo(FIFO2, FILE_MODE) < 0) && (errno != EEXIST) ) {
        unlink(FIFO1);
        err_sys("can't create %s",FIFO2);
    }


    writefd= Open(FIFO1,O_WRONLY,0);
    readfd = Open(FIFO2,O_RDONLY,0);

    client(readfd,writefd);

    Close(readfd);
    Close(writefd);

    Unlink(FIFO1);
    Unlink(FIFO2);

    exit(0);
}

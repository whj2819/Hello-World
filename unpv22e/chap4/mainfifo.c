#include "unpipc.h"
#include <unistd.h>

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"


void client(int,int);
void server(int,int);



int
main(int argc, char *argv[])
{

    int readfd,writefd;
    pid_t childpid;


    if ((mkfifo(FIFO1, FILE_MODE) < 0) && (errno != EEXIST) )
        err_sys("can't create %s",FIFO1);
    if ((mkfifo(FIFO2, FILE_MODE) < 0) && (errno != EEXIST) ) {
        unlink(FIFO1);
        err_sys("can't create %s",FIFO2);
    }


    if ((childpid = Fork()) == 0) {
        readfd = Open(FIFO1,O_RDONLY,0);
        writefd= Open(FIFO2,O_WRONLY,0);

        server(readfd,writefd);
        exit(0);
    }
    
    writefd= Open(FIFO1,O_WRONLY,0);
    readfd = Open(FIFO2,O_RDONLY,0);

    client(readfd,writefd);

    Waitpid(childpid,NULL,0);

    Close(readfd);
    Close(writefd);

    Unlink(FIFO1);
    Unlink(FIFO2);

    exit(0);
}

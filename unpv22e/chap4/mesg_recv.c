#include "mesg.h"

ssize_t
mesg_recv(int fd, struct mymesg *mptr)
{
    size_t len;
    ssize_t n;


    if ( (n = Read(fd, mptr, MESGDRSIZE) ) == 0)
        return 0;
    else if (n != MAXMESGDATA)
        err_quit("message header:expected %d, got %d", MESGDRSIZE, n);

    if ( (len = mptr->mesg_len) > 0) 
        if ( (n = Read(fd, mptr->data, len) ) != len)
            err_quit("message data:expected %d, got %d", len, n);

    return (len);
}

ssize_t
Mesg_recv(int fd, struct mymesg *mptr)
{
    return ( mesg_recv(fd,mptr) );
}

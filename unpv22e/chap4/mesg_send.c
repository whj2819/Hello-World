#include "mesg.h"



ssize_t
mesg_send(int fd, struct mymesg *mptr)
{
    return (write(fd,mptr,MESGDRSIZE + mptr->mesg_len));
}

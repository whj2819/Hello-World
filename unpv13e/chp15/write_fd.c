#include "unp.h"

ssize_t
write_fd(int fd, void *ptr, size_t nbytes, int sendfd)
{
    struct msghdr msg;
    struct iovec iov[1];

#if HAVE_MSGHDR_MSG_CONTROL
    /* 
     *  为什么这个union可以确保
     *  字符数组正确对其
     * 
     * */
    union {
        struct cmghdr cm;
        char control[CMSG_SPACE(sizeof(int))]; 
    }control_un;
    struct cmghdr *cmptr;

    msg.msg_control = control_un.control;
    msg.msg_controllen = sizeof(control_un.control);

    cmptr = CMSG_FIRSTHDR(&msg);
    cmptr->cmsg_len = CMSG_LEN(sizeof(int));
    cmptr->level = SOL_SOCKET;
    cmptr->type = SCM_RIGHTS;
    *((int *)CMSG_DATA(cmptr)) = sendfd;
#else
    msg.msg_accrights = (caddr_t) & sendfd;
    msg.msg_accrightslen = sizeof(int);
#endif
    msg.msg_name = NULL;
    msg.msg_namelen = 0;

    iov[0].iov_base = ptr;
    iov[0].iov_len = nbytes;

    msg.msg_iov = iov;
    msg.msg_iovlen = 1;

    return( sendmsg(fd, &msg, 0) ); 
}

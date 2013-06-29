#inlcude "unpipc.h"


#define MAXMESGDATA (PIPE_BUF - 2 * sizeof(long))

#define MESGDRSIZE (sizeof(struct mymesg) - MAXMESGDATA)

struct mymesg {
    long mesg_len;
    long mesg_type;
    char mesg_data[MAXMESGDATA];
};


ssize_t mesg_send(int,struct mymesg *);
void Mesg_send(int,struct mymesg *);
ssize_t mesg_recv(int,struct mymesg *);
ssize_t Mesg_send(int,struct mymesg *);

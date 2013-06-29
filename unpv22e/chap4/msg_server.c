#include "mesg.h"


void
server(int readfd, int writefd)
{
    FILE *fp;
    ssize_t n;
    struct mymesg mesg;

    mesg.mesg_type = 1;
    if ( (n = Mesg_recv(readfd,&mesg)) ==0)
        err_quit("pathname missing");
    mesg.mesg_data[n] = '\0';

    if ( (fp = fopen(mesg.mesg_data,"r")) == NULL) {
        snprintf(mesg.mesg_data + n, sizeof(mesg.mesg_data) -n,
                ":can't open %s\n", strerror(errno));
        mesg.mesg_len = strlen(mesg.mesg_data);
        Mesg_send(writefd,&mesg);
    } else {
        while(Fgets(mesg.mesg_data, MAXMESGDATA, fp) != NULL) {
            mesg.mesg_len = sizeof(mesg.mesg_data); 
            Mesg_send(writefd, &mesg);
        }
        Fclose(fd);
    }

    mesg.mesg_len = 0;
    Mesg_send(writefd, &mesg);
}


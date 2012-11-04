#include "unp.h"

int 
main(void)
{
    const char *ip = "192.168.56.111";
    char *ntoip = NULL;
    struct in_addr addr;
    int rv = 0;

    //rv = inet_aton(ip,&addr);
    //printf("rv:%d ip:%s %ld \n",rv,ip,addr.s_addr);

    addr.s_addr = 1865984192;
    ntoip = inet_ntoa(addr);
    printf("notoip:%s \n",ntoip);

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>



int
main(void)
{
    uid_t uid,euid;

    printf("uid:%d euid:%d \n",getuid(),geteuid() );

    return 0;
}

#include <stdio.h>
#include <unistd.h>

#define __DEBUG__

#ifdef __DEBUG__
    #define DEBUG(format,...) printf("file: %s,Line:%05d: "format"\n",__FILE__,__LINE__,##__VA_ARGS__)

#else
    #define DEBUG(format,...)
#endif


int
main(int argc, char *argv[])
{
    char str[] = "Hello World";

    DEBUG("A ha,check me:%s",str);

    return 0;
}

#include <stdio.h>

int
main(int argc,char **argv)
{
    int rv = 0;
    /*
    const char *old = "/home/gongde/study/Hello-World/testcase/C/File/aaa.c";
    const char *new= "/home/gongde/study/Hello-World/testcase/C/File/bbbb.c";
    */

    rv = rename("aaa.c","ccccccc.c");

    printf("rv = %d \n",rv);
    if (rv) {
        printf("rename error \n");
        return -1;
    }

    return 0;
}

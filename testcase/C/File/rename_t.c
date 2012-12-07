#include <stdio.h>
#include <unistd.h>

int
main(int argc,char **argv)
{
    int rv = 0;
    
    //rv = rename("aaa.c","ccccccc.c");
    //rv = rename("test/a/b/c/","testb/c/b/a/");
    rv = access("aaa.c",0);
    printf("rv = %d \n",rv);
    if (rv) {
        printf("rename error \n");
        return -1;
    }
    printf("file is exist \n");

    return 0;
}

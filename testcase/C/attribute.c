#include <stdio.h>


static __attribute__((constructor)) void before()
{
    printf("hello\n");
}

static __attribute__((destructor)) void after()
{
    printf("world\n");
}

int main(int argc, const char *argv[])
{
    
    return 0;
}




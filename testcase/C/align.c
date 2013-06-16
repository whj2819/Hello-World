#include <stdio.h>

#pragma pack(4)

typedef struct {
    char a;
    int b;
    short c;
    char d;
}TEST_t;

int
main(int argc, char *argv[])
{
    TEST_t a;

    printf("[%d] \n",sizeof(a) );

    return 0;
}

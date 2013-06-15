#include <stdio.h>

#pragma pack(2)

typedef struct test {
    int a;
    double m4;
    char m1;
    int m3;
}TEST_t;

typedef struct {
    char b;
    int a;
    short c;
}C_t;

int
main(int argc, char *argv[])
{
    TEST_t a;
    C_t b;

    //printf("[%d] \n",sizeof(a) );
    printf("[%d] \n",sizeof(b) );

    return 0;
}

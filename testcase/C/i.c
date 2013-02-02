#include <stdio.h>


int
main(int argc,char **argv)
{
    unsigned short a = 0x55ac;
    unsigned char b = 0;


    b = ((a & 0x03) << 6) | ((a & 0x03) << 4)\
        |((a & 0x03) << 2) | (a & 0x03);


    printf("____ 0x%x \n",a);
    printf("==== 0x%x \n",b);
    return 0;
}

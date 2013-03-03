#include <stdio.h>
#include "cbase/util.h"


int
main(int argc, char *argv[])
{
    //char s[] = "HELLO WORLD";
    char s[] = "Hello---";



     printf("%d \n",__string_endswith(s,"---------------"));

     return 0;
}

#include <stdio.h>
#include "cbase/util.h"


int
main(int argc, char *argv[])
{
    //char s[] = "HELLO WORLD";
    char s[] = "    Hello world";



     printf("%s \n",__string_trim(s));

     return 0;
}

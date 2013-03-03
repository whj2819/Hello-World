#include <stdio.h>
#include "cbase/util.h"
//#include "cbase/defs.h"


int
main(int argc, char *argv[])
{
    //char s[] = "HELLO WORLD";
    char s[] = "12345";



     printf("%d \n",__string_is_numberic(s));

     return 0;
}

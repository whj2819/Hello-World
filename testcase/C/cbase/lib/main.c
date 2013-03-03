#include <stdio.h>
#include "cbase/util.h"


int
main(int argc, char *argv[])
{
    //char s[] = "HELLO WORLD";
    char s[] = "hello world";
    char *c = NULL;


     //c = __string_tolower(s);
     c = __string_toupper(s);

     printf("%s \n",c);

     return 0;
}

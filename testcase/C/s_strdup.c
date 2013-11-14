#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char *argv[])
{
    char *s = "Hello strdup";
    char *d = NULL;

    d = strdup(s);

    printf("[%s] \n", d);
    free(d);


    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void 
f(void)
{
    int *x = malloc( 10 * sizeof(int) );

    x[10] = 0;

}


int main(int argc, const char *argv[])
{
    int i;
    char a[1024] = {0};

    f();
    
    printf("i = %d \n", i);

    return 0;
}



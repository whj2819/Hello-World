#include <stdio.h>
#include <stdlib.h>


#define BUFSIZE 8
int
__cmp(const void *a, const void *b)
{

    //return *(int*)a - *(int*)b;
    return *(int*)b - *(int*)a;
}


int
main(int argc, char *argv[])
{
    int i;
    int a[BUFSIZE] = {7,5,3,8,2,4,1,9};

    qsort( a, BUFSIZE, sizeof(int), &__cmp );

    for (i=0; i<BUFSIZE; i++)
        printf("a[%d] = %d \n",i,a[i]);
    printf("\n\n");

    return 0;
}

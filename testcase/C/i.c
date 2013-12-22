#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int *p = (int *)malloc(sizeof(int));
    int *q = (int *)malloc(sizeof(int));
    int i;


    for (i = 0; i < 400; i++) {
        p[i] = i;
    }
    q[0] = 0;

    free(q);
    free(p);


    return 0;
}

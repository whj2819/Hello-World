#include <stdio.h>




int main(int argc, const char *argv[])
{
    int x[4] = {3,1,4,2};
    int i,j;
    int t;



    for (i = 1; i < 4; i++) {
        for (j = i; j>0 && x[j-1] > x[j] ; j--) {
            t = x[j];
            x[j] = x[j-1];
            x[j-1] = t;
        } 
    }


    for (i = 0; i < 4; i++)
        printf("%d ", x[i]);


    printf("\n");
    return 0;
}

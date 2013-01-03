#include <stdio.h>

typedef unsigned short u16;

int
main(int argc,char **argv)
{
    u16 a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int i,j;
    int row = 4,col = 3;

    for (i=0; i<12; i++) 
        printf("%d ",a[i]);
    printf("\n\n\n");


    for (i=0;i<col;i++) {
        for(j=row;j>=0;j--) {
            printf("%d ",*(a+j*(col-1)+1+i));
        }
        printf("\n");
    }




    return 0;
}

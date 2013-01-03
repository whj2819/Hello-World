#include <stdio.h>

typedef unsigned short u16;

int
main(int argc,char **argv)
{
    u16 a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    u16 tmp[3][4];
    int i,j;
    int row = 3,col = 4;
    u16 *p  = a;

    for (i=0; i<12; i++) 
        printf("%d ",a[i]);
    printf("\n\n\n");

    for (i = 0;i<row;i++) {
        for(j = 0;j<col;j++) {
            tmp[i][j] = *(p+j);
        }
        p += col;;
    }
    for (i = 0;i<row;i++) {
        for(j = 0;j<col;j++) {
            printf("%d ",tmp[i][j]);
        }
        printf("\n");
    }
        printf("\n");
        printf("\n");
        printf("\n");

        p = a;

    for (i = 0;i<col;i++) {
        for(j = row-1;j>=0;j--) {
             *(p+i)= tmp[j][i];
             printf("%d ",*(p+i));
        }
        p += 4;
        printf("\n");
    }



    return 0;
}

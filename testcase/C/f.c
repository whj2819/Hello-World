#include <stdio.h>
#include <stdlib.h>

typedef unsigned short u16;


int __convert(u16 *src,u16 row,u16 col,u16 *dest)
{

    return 0;
}
static int k =0;
int
main(int argc,char **argv)
{
    //u16 a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    u16 a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    u16 data[15]  = {0};
    int i,j,m;
    int row = 3,col = 5;
    u16 tmp[3][5];
    u16 b[3][5];
    u16 *q;

    u16 *p =a;

    printf("main func\n");
    for (i = 0;i<row;i++) {
        for(j = 0;j<col;j++) {
            tmp[i][j] = *(p+j);
        }
        p += col;;
    }
    for (i = 0;i<row;i++) {
        for(j = 0;j<col;j++) {
            printf("%d  ",tmp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("================\n");

    for (i = 0;i<col;i++) {
        for(j = row-1;j>=0;j--) {
            b[i][row-j-1]= tmp[j][i];
            printf("%d  ",b[i][row-j-1]);
        }
        printf("\n");
    }
    printf("__________________-\n");

    for (i = 0;i<col;i++) {
        for (j = 0;j<row;j++) {
            data[k] = b[i][j];
            k++;
            printf("%d  ",b[i][j]);
        }
    }
    printf("\n\n__++++____________-\n");

    for (i = 0;i< 15;i++) {
        printf("%d  ",data[i]);
    }

    k = 0;
    printf("\n\n");


    return 0;
}

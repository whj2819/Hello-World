#include <stdio.h>

typedef unsigned short u16;
int
convert(u16 *src,int row,int col,u16 *dest)
{
    int i,j;
    for (i=0 ;i<col; i++) {
        for (j=row; j>=0; j--) {
            printf("%d ",src[j][i]);
        }
        printf("\n");
    }

    return 0;
}

int
main(int argc,char **argv)
{
    u16 a[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    u16 b[3][3] = {{0}};

    int i,j;
    int rv = 0;

    for (i = 0;i<3;i++) {
        for(j = 0;j<3;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    rv = convert(a,3,3,b);
    if (rv) {
        printf("error \n");
    }
#if 0
    for (i=0;i<3;i++) {
        for(j=2;j>=0;j--) {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
#endif

    return 0;
}

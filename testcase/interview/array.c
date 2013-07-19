/*
    5 85 4 2 68
    78 82 75 41 14
    79 47 38 1 47
    1 2 14 65 13
    96 87 32 14 21
按下列步骤编码：(使用C语言)
    1．分配两个5x5数组a和b，将数组a按上图所示赋初值。
    2．对于数组a中每一个元素a[i][j]，从它的相邻元素中选取中间值填入b[i][j]。
    3．打印b数组。

    例如：
    a[0][2]的相邻元素为85、82、75、41、2，升序排序后序列为2、41、75、82、85，
    取中间值方法:
    中间值索引 = 相邻元素个数 / 2
    即5 / 2 = 2，中间值为75，将6填入b[0][2]位置。

    a[2][1] 的相邻元素为78、82、75、79、38、1、2、14，
    排序后序列为1、2、14、38、75、78、79、82，中间值为75，填入b[2][1]。

*/

#include <stdio.h>


void
bubble_sort(int *buf, int size)
{
    int i, j,tmp;

    for (i=0; i<size-1; i++) 
        for (j=0; j<size-i-1; j++) 
            if (buf[j] > buf[j + 1]) {
                tmp = buf[j];
                buf[j] = buf[j + 1];
                buf[j + 1] = tmp;
            }
}


int
get_mid_value(int *buf, int size)
{
    int n;

    bubble_sort(buf, size);
    n = buf[size/2];

    return n;
}


int
main(void)
{
    int a[5][5] = {
        {5,85,4,2,68},
        {78,82,75,41,14},
        {79,47,38,1,47},
        {1,2,14,65,13},
        {96,87,32,14,21}
    };

    int pos[8][2] = {
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,-1},
        {0,1},
        {1,-1},
        {1,0},
        {1,1}
    };
    int b[5][5] = { {0}, {0} };
    int tmp[8] ={0};
    int i, j, k;
    int cnt = 0;

    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            for (k=0; k<8; k++) {
                if ( i + pos[k][0] < 0 || i + pos[k][0] > 4
                        || j + pos[k][1] < 0 || j + pos[k][1] >4)
                    continue;
                 else
                    tmp[cnt++] = a[ i + pos[k][0] ][ j + pos[k][1] ];
            }       
            //排序,求中间值,赋值给数组b
            b[i][j] = get_mid_value(tmp, cnt);
            cnt = 0;
        }
    }

#if 1 
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            printf("%d   ", b[i][j]);
        }
        printf("\n");
    }
#endif
    return 0;
}

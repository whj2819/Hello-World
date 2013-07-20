/*
    描述
        现在要写一个程序，实现给三个数排序的功能
    输入
        输入三个正整数
    输出
        给输入的三个正整数排序
    样例输入
        20 7 33
    样例输出
        7 20 33
*/
#include <stdio.h>

void
bubble_sort(int *buf, int s)
{
    int i, j, tmp;

    for (i=0; i<s-1; i++)
        for (j=0; j<s-i-1; j++)
            if (buf[j] > buf[j + 1]) {
                tmp = buf[j];
                buf[j] = buf[j + 1];
                buf[j + 1] = tmp;
            }
}


int
main(void)
{
    int a[3] = {0};
    int i;

    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    bubble_sort(a, 3);

    for (i=0; i<3; i++)
        printf("%d ", a[i]);
    printf("\n");


    return 0;
}

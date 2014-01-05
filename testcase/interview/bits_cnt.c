/*
 * 计算 变量包含多少位1
  *
 */
#include <stdio.h>

int
main(void)
{
    int cnt = 0;
    int x = 7;

    while (x) {
        cnt ++;
        x = x & (x-1);
    }
    printf("[%d]\n", cnt);

    return 0;
}


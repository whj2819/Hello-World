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
    int n, k; 
    int a, b;
    int cnt=1;
    int s[4] = {0};

    scanf("%d", &k);
    while(k--) {
        scanf("%d", &n);
        while(n != 6174) {
            s[0] = n/1000;
            s[1] =n/100%10;
            s[2] =n%100/10;
            s[3] =n%10;

            bubble_sort(s, 4); // 升序排列
            a = s[3] * 1000 + s[2] * 100 + s[1] * 10 + s[0];
            b = s[0] * 1000 + s[1] * 100 + s[2] * 10 + s[3];
            n = a - b;
            cnt++;
        }
        printf("%d \n", cnt); 
        cnt = 0;
    }

    return 0;
}

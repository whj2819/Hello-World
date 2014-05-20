#include <stdio.h>
#include <math.h>

long int min(long int n1, long int n2, long int n3)
{
    long int t = n1 < n2 ? n1 : n2;
    return t < n3 ? t : n3;
}

int main()
{
    long int ug[1500];
    int c2 = 0, c3 = 0, c5 = 0, N;

    ug[0] = 1;
    N = 1;

    while (N < 1500) {
        ug[N] = min(ug[c2] * 2, ug[c3] * 3, ug[c5] * 5);
        if (ug[N] == ug[c2] * 2)	// 因为可能数相等，所以不能else if   
            c2++;

        if (ug[N] == ug[c3] * 3)
            c3++;

        if (ug[N] == ug[c5] * 5)
            c5++;
        N++;

    }

    printf("%ld\n", ug[N - 1]);

    return 0;
}

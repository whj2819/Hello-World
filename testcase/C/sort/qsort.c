#include <stdio.h>

#define MAXN 128
int x[MAXN] = {55, 41, 59, 26, 53, 58, 97, 93};

void
swap(int i, int j)
{
    int t;
    t = x[i];
    x[i] = x[j];
    x[j] = t;
}

void
qsort1(int l, int u)
{
    int i, m;

    if (l >= u)
        return;
#if 0
    m = u + 1;
    for(i=u; i>=l; i--)
        if (x[i] >= x[l])
            swap(--m, i);
    
    qsort1(l, m-1);
    qsort1(m+1, u);
#else
    m = l;
    for (i=l+1; i<=u; i++)
        if (x[i] < x[l])
            swap(++m, i);

    swap(l, m);
    qsort1(l, m-1);
    qsort1(m+1, u);
#endif
}


int
main(void)
{
    int i;

    for (i=0; i<8; i++)
        printf("%d ", x[i]);
    printf("\n");
    qsort1(0,7);

    for (i=0; i<8; i++)
        printf("%d ", x[i]);
    printf("\n");
    return 0;
}

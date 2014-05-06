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
qsort(int l, int u)
{
    int m;
    int i;

    if (l >= u)
        return ;

    m = l;
    for (i = l+1; i <=u; i++)
        if (x[i] < x[l])
            swap(++m, i);

    swap(l,m);
    qsort(l, m-1);
    qsort(m+1, u);
}




int main(int argc, const char *argv[])
{
    int i = 0;

    qsort(0,7);

    for (i = 0; i < 8; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    
    return 0;
}

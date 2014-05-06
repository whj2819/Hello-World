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
    int i, j;
    int t;

    if (l >= u)
        return ;

    t = x[l];
    i = l;
    j = u + 1;


    for (;;) {
        do {
            i++;
        }while(i<=u && x[i] < t);

        do {
            j--;
        }while(x[j] > t);

        if (i > j)
            break;
        swap(i, j);
    }

    swap(l, j);
    qsort(l, j-1);
    qsort(j+1, u);
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

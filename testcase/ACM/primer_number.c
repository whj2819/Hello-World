#include <stdio.h>
#include <math.h>


int
main(void)
{
    int n;
    int i;

    while(1) {
        scanf("%d", &n);
        getchar();

        if (n == 0)
            break;

        for (i=2; i<sqrt(n); i++)
            if (n%i == 0)
                break;

        if (i > sqrt(n))
            printf("%d is a primer number \n", n);
        else
            printf("%d is not a primer number \n", n);

    }
    return 0;
}

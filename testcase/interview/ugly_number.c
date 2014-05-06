#include <stdio.h>


int main(int argc, const char *argv[])
{
    int num[1501] = {0};
    int two = 0;
    int three = 0;
    int five = 0;
    int i,j;

    num[0] = 0;
    num[1] = 1;

    for (i = 1; i < 1500; i++) {
        for (j = 1; j<= i; j++) {
            if ( (2*num[j-1] <= num[i])  \
                    && (2*num[j] > num[i]) ) 
                two = num[j] *2;
        }

        for (j = 1; j<= i; j++) {
            if ( (3*num[j-1] <= num[i])  \
                    && (3*num[j] > num[i]) ) 
                three = num[j] *3;
        }


        for (j = 1; j<= i; j++) {
            if ( (5*num[j-1] <= num[i])  \
                    && (5*num[j] > num[i]) ) 
                five = num[j] *5;
        }

        if(two>=three && five>=three)
            num[i+1] = three;
        else if(two>=five && three>=five) 
            num[i+1] = five;
        else if(five>=two && three>=two)
            num[i+1] = two;
    }

    printf("1500'th ugly number %d \n", num[1500]);

    return 0;
}
#if 0
int main(int argc, const char *argv[])
{
    int number = 1500;
    int index = 1;

    while (number > 0) {
        int d = index;

        while(d % 2 == 0)
            d /= 2;
        while(d % 3 == 0)
            d /= 3;
        while(d % 5 == 0)
            d /= 5;

        if (d == 1)
            number--;
        index ++; 
    }
    printf("1500'th ugly number %d \n", index);
    
    return 0;
}
#endif

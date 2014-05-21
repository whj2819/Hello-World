include <stdio.h>

union t {
    char c;
    int i;
};

int
main(void)
{
    int i = 1;

    if ( (*(char*)&i) == 1)
        printf("%d \n", i);


    return 0;

}

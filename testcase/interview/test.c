#include <stdio.h>


struct test {
    int a;
    int b;
    char c[0];
};

int main(int argc, const char *argv[])
{
    printf("%d \n", sizeof(struct test));
    
    return 0;
}

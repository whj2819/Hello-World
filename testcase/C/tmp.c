#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void func (void)
{
    int a = 10;

    /* static int b = a; */

}

int main(int argc, const char *argv[])
{
    /* func(); */

    int a = 10;
    static int b = a;
    
    return 0;
}

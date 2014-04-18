#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int *func (void)
{
    int i;
    i = 10;

    return &i;

}

int main(int argc, const char *argv[])
{
    int b =  func();
    
    return 0;
}

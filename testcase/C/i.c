#include <stdio.h>
#include <stdlib.h>



struct {
    int x;
    struct {
        int y, z;

    }nested;

}i = {.nested.y=5,6,.x=1,2};

int main(int argc, const char *argv[])
{
    printf("y %d z: %d \n", i.nested.y, i.nested.z);
    
    return 0;
}

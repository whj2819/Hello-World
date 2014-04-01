#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "except.h"
#include "mem.h"

struct demo{
    int a;
    int b;
};

int main(int argc, const char *argv[])
{
    struct demo t;

    ALLOC( sizeof(t) );


    
    return 0;
}

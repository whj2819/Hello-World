#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "except.h"
#include "mem.h"

const Except_T Mem_Failed = { "Allocation Failed" };
void *
Mem_alloc(long nbytes, const char *file
    , int line)
{
    void *ptr;

    assert(nbytes > 0);

    ptr = malloc(nbytes);
    if (ptr == NULL) {
        if (file == NULL)
            RAISE(Mem_Failed);
        else
            Except_raise(&Mem_Failed, file, line); 
    }
    return ptr;
}

void *
Mem_calloc(long count, long nbytes \
    , const char *file, int line)
{

}

#include <stdio.h>
#include <stdlib.h>

#define MALLOC_ALIGNMENT ((size_t)8u)
#define SIZE_T_ONE    ((size_t)1)
#define CHUNK_ALIGN_MASK (MALLOC_ALIGNMENT - SIZE_T_ONE)
#define is_aligned(A) (((size_t)((A)) & (CHUNK_ALIGN_MASK)) == 0 )

#define align_offset(A) \
    ( (((size_t)(A) & (CHUNK_ALIGN_MASK) ) == 0 )? 0 :\
( (MALLOC_ALIGNMENT - ((size_t)((A)) & CHUNK_ALIGN_MASK)) & CHUNK_ALIGN_MASK ))


int main(int argc, const char *argv[])
{
    int *p = NULL;


    p = (int *)malloc(10);
    p = (int *)0x0000008;

    printf("%p is aligned ? [%d] offset %d\n", p, is_aligned(p), align_offset(p) );
    return 0;
}

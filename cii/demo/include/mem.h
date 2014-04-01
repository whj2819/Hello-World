#ifndef MEM_INCLUDED
#define MEM_INCLUDED




extern void *Mem_alloc(long nbytes, const char *file, int line);

extern void *Mem_calloc(long count long nbytes, \
        const char *file, int line);




#endif

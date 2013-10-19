#include "unpipc.h"


#define MAXNITEMS    1000
#define MAXNTHREADS  10

int    nitems;

struct  {
    pthread_mutex_t mutex;
    int buf[MAXNITEMS];
    int nput;
    int nval;
}shared = {
    PTHREAD_MUTEX_INITIALIZER
};


void *produce(void *), *consume(void *);

int
main(int argc, char *argv[])
{
    int     i, nthreads, count[MAXNITEMS];
    pthread_t     tid_produce[MAXNTHREADS], tid_consume;


    if (argc != 3)
        err_quit("usage: producons2 <#items> <#threads>");

    nitems = min(atoi(argv[1]), MAXNITEMS);
    nthreads= min(atoi(argv[2]), MAXNTHREADS);
    
    return 0;
}

#include "unpipc.h"

#define MAXNITEMS    1000000
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


void *
produce(void *arg)
{
   for (; ;) {
       Pthread_mutex_lock(&shared.mutex);
       if (shared.nput >= nitems){
           Pthread_mutex_unlock(&shared.mutex);
           return (NULL);
       }
       shared.buf[shared.nput] = shared.nval;
       shared.nput++;
       shared.nval++;
       Pthread_mutex_unlock(&shared.mutex);
       *((int *)arg) += 1;
   }

}

void *
consume(void *arg)
{
    int    i;

    for (i = 0; i < nitems; i++) 
        if (shared.buf[i] != i)
            printf("buf[%d] = %d \n", i, shared.buf[i]);

    return (NULL);
}

int
main(int argc, char *argv[])
{
    int     i, nthreads, count[MAXNITEMS];
    pthread_t     tid_produce[MAXNTHREADS], tid_consume;

    if (argc != 3)
        err_quit("usage: producons2 <#items> <#threads>");
    nitems = min(atoi(argv[1]), MAXNITEMS);
    nthreads= min(atoi(argv[2]), MAXNTHREADS);

    Set_concurrency(nthreads);

    for (i = 0; i < nthreads; i++) {
        count[i] = 0;
        Pthread_create(&tid_produce[i], NULL, produce, &count[i]); 
    }

    for (i = 0; i < nthreads; i++) {
        Pthread_join(tid_produce[i], NULL);
        printf("count[%d] = %d \n", i, count[i]);
    }

    Pthread_create(&tid_consume, NULL, consume, NULL);
    Pthread_join(tid_consume, NULL);

    return 0;
}

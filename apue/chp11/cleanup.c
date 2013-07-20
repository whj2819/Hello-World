#include "apue.h"
#include <pthread.h>

void
cleanup(void *arg)
{
    printf("cleanup %s \n", (char *)arg );

}

void *
thr_fn1(void *arg)
{
    printf("thread 1 start \n");
    pthread_cleanup_push(cleanup, "thread 1 first handler");
    pthread_cleanup_push(cleanup, "thread 1 second handler");
    printf("thread 1 push complete \n");

    if (arg) {
        printf("1111111before arg \n");
        return ((void *)1);
    }

    printf("1111111111after arg \n");
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);

    return ((void *)1);
}

void *
thr_fn2(void *arg)
{
    printf("thread 2 start \n");
    pthread_cleanup_push(cleanup, "thread 2 first handler");
    pthread_cleanup_push(cleanup, "thread 2 second handler");
    printf("thread 2 push complete \n");

    if (arg) {
        printf("2222before arg \n");
       pthread_exit( (void *)2); 
    }

    printf("2222222after arg \n");

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);

    pthread_exit( (void *)2); 
}

int
main(void)
{
    int err;
    pthread_t tid1, tid2;
    void *tret;


    err = pthread_create(&tid1,NULL, thr_fn1,(void *)1);
    if (err != 0)
        err_quit("can't create thread 1: %s \n", strerror(err) );

    err = pthread_create(&tid2,NULL, thr_fn2,(void *)1);
    if (err != 0)
        err_quit("can't create thread 2: %s \n", strerror(err) );

    err = pthread_join(tid1, &tret);
    if (err != 0)
        err_quit("can't join thread 1: %s \n", strerror(err) );
    printf("thread 1 exit code %d \n",(int)tret);

    err = pthread_join(tid2, &tret);
    if (err != 0)
        err_quit("can't join thread 2: %s \n", strerror(err) );
    printf("thread 2 exit code %d \n",(int)tret);


    exit(0);
}

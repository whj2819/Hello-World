#include "apue.h"
#include <pthread.h>


void *
test(void *arg)
{
    printf("hello world \n");


    return ((void *)0);

}

int
makethread(void *(*fn)(void *), void *arg)
{
    int      err;
    pthread_t    tid;
    pthread_attr_t attr;

    err = pthread_attr_init(&attr);
    if (err != 0)
        return err;

    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (err ==0)
        err = pthread_create(&tid, &attr, fn, arg);
    pthread_attr_destroy(&attr);
    return err;
}

int main(int argc, const char *argv[])
{
    int err;

    err = makethread(&test, NULL);
    printf("main exit %d ....... \n", err);

    sleep(3);

    return 0;
}

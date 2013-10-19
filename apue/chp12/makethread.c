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
    size_t stacksize;
    int concurrency;

    err = pthread_attr_init(&attr);
    if (err != 0)
        return err;

    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (err ==0)
        err = pthread_create(&tid, &attr, fn, arg);


    err = pthread_attr_getstacksize(&attr, &stacksize);
    concurrency = pthread_getconcurrency();
    pthread_attr_destroy(&attr);

    printf("stacksize :0x%x concurrency: %d\n", stacksize, concurrency);
    return err;
}

int main(int argc, const char *argv[])
{
    int err;
    int min, max, addr;

    err = makethread(&test, NULL);
    min = sysconf(_SC_THREAD_ATTR_STACKSIZE);
    addr = sysconf(_SC_THREAD_ATTR_STACKADDR);

    printf("addr: 0x%x, min: 0x%x  ....... \n", addr, min);


    sleep(3);

    return 0;
}

#include "unpipc.h"

#define NBUFF 10

int nitems;

struct {
    int buff[NBUFF];
    sem_t mutex, nempty, nstored;
}shared;

void *produce(void *), *consume(void *);

int main(int argc, char *argv[])
{
    pthread_t tid_produce, tid_consume;

    if (argc != 2)
        err_quit("usage: prodcons <#items>");
    nitems = atoi(argv[1]);
    Sem_init(&shared.mutex, 0, 1);
    Sem_init(&shared.nempty, 0, NBUFF);
    Sem_init(&shared.nstored, 0, 0);

    Set_concurrency(2);

    Pthread_create(&tid_produce, NULL, produce, NULL);
    Pthread_create(&tid_consume, NULL, consume, NULL);

    Pthread_join(tid_produce, NULL);
    Pthread_join(tid_consume, NULL);

    Sem_destroy(&shared.mutex);
    Sem_destroy(&shared.nempty);
    Sem_destroy(&shared.nstored);

    return 0;
}

void *
produce(void *arg)
{
    int i;

    for (i = 0; i < nitems; i++) {
        Sem_wait(&shared.nempty);
        Sem_wait(&shared.mutex);
        shared.buff[i % NBUFF] = i;
        Sem_post(&shared.mutex);
        Sem_post(&shared.nstored);
    }

    return NULL; 
}

void *
consume(void *arg)
{
    int i;

    for (i = 0; i < nitems; i++) {
        Sem_wait(&shared.nstored);
        Sem_wait(&shared.mutex);
        if ( shared.buff[i % NBUFF] != i)
            printf("buff[%d] = %d \n", i, shared.buff[i % NBUFF]); 
        printf("buff[%d] = %d \n", i, shared.buff[i % NBUFF]); 
        Sem_post(&shared.mutex);
        Sem_post(&shared.nempty);
    }

    return NULL;
}


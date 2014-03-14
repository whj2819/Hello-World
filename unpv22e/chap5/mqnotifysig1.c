#include "unpipc.h"


mqd_t mqd;
void *buff;
struct mq_attr attr;
struct sigevent sigev;

static void sig_usr1(int);

#if 0
void
my_handle(union sigval v)
{
    printf("my handle %d\n", v);
}
#endif

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        err_quit("usage mqnotifysig1 <name>"); 
    }

    mqd = Mq_open(argv[1], O_RDONLY);
    Mq_getattr(mqd, &attr);
    buff = Malloc(attr.mq_msgsize);

    Signal(SIGUSR1, sig_usr1);
    sigev.sigev_notify = SIGEV_SIGNAL;
    sigev.sigev_signo = SIGUSR1;
#if 0
    /* 验证struct sigevent SIGEV_THREAD 的用法. */
    sigev.sigev_notify = SIGEV_THREAD;
    sigev.sigev_value.sival_int = 10;
    sigev.sigev_notify_function = my_handle;
    sigev.sigev_notify_attributes = NULL;
    Mq_notify(mqd, &sigev);
#endif


    for (; ;) 
       pause(); 

    exit(0); 
}

static void
sig_usr1(int signo)
{
    ssize_t n;

    Mq_notify(mqd, &sigev);
    n = Mq_receive(mqd, buff, attr.mq_msgsize, NULL);
    printf("sigusr1 received, read %ld bytes\n", (long)n);

    return ; 
}

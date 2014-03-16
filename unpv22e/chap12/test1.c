#include "unpipc.h"

#if 1
void
handle(int arg)
{
    printf("got SIGSEGV \n");
    exit (0);

}
#endif

int
main(int argc, char **argv)
{
    int fd, i;
    char *ptr;
    size_t filesize, mmapsize, pagesize;

    if (argc != 4)
        err_quit("usage: test1 <pathname> <filesize> <mmapsize>");

    filesize = atoi(argv[2]);
    mmapsize= atoi(argv[3]);

    fd = Open(argv[1],O_RDWR | O_CREAT | O_TRUNC, FILE_MODE);
    Lseek(fd, filesize-1, SEEK_SET);
    Write(fd, "", 1);


    ptr = Mmap(
                NULL
                , mmapsize
                , PROT_READ | PROT_WRITE
                , MAP_SHARED
                , fd
                , 0
            );
    Close(fd);

    pagesize = Sysconf(_SC_PAGESIZE);
    printf("PAGESIZE = %ld \n", (long)pagesize);
#if 1
    for(i=0; i<max(filesize, mmapsize); i += pagesize) {
        printf("ptr[%d] = %d \n", i, ptr[i]);
        ptr[i] = 1;
        printf("ptr[%d] = %d \n", i + pagesize - 1, ptr[i + pagesize - 1]);
        ptr[i + pagesize - 1] = 1;
    }
    printf("ptr[%d] = %d \n", i, ptr[i]);
#endif

#if 0
    /*
     * mmap测试. ./test1 foo 8200 8200
     * 当读取到第3个8192的时候捕获到SIGSEGV信号. 
     * 那这样子的话页面大小是否就是按8192来
     * 计算呢.
     *
     * 测试sigbus. ./test1 foo 5000 9000
     * 这样子可以得到sigbus err. 
     *
     *
     */
    struct sigaction act;
    act.sa_flags = 0;
    act.sa_handler = handle;
    /* signal(SIGSEGV, handle); */
    sigaction(SIGSEGV, &act, NULL); 

    pagesize = 8192;
    for(i=0; ; i += pagesize) {
        printf("ptr[%d] = %d \n", i, ptr[i]);
        ptr[i] = 1;
        printf("ptr[%d] = %d \n", i + pagesize - 1, ptr[i + pagesize - 1]);
        ptr[i + pagesize - 1] = 1;
    }
    printf("ptr[%d] = %d \n", i, ptr[i]);
#endif

    exit (0);
}

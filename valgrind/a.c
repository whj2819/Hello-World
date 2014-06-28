/*
 * valgrind setrlimit 测试.
 *
 * 官方文档说明.
 *          Implement an emulated soft limit for file descriptors in addition to
 * the current reserved area, which effectively acts as a hard limit. The
 * setrlimit system call now simply updates the emulated limits as best
 * as possible - the hard limit is not allowed to move at all and just
 * returns EPERM if you try and change it. This should stop reductions
 * in the soft limit causing assertions when valgrind tries to allocate
 * descriptors from the reserved area.
 * (This actually came from bug #83998).
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

/*
 * gcc -Wall -g -DVALGRIND a.c
 */
int main(int argc, const char *argv[])
{
    struct rlimit limit;
    int iRet = 0;

#ifdef VALGRIND
    limit.rlim_cur = 1000;
    limit.rlim_max = 1000;

    /*
     * 当用valgrind 跑程序时
     * setrlimit返回EPRM(errno=1);
     *
     */
    iRet = setrlimit(RLIMIT_NOFILE, &limit);
    if( -1 == iRet)
        printf("setrlimit error :%d errno: %d \n", iRet, errno);
    else
        printf("setrlimit error :%d errno: %d \n", iRet, errno);
#endif
        printf("Hello world\n");
    
    return 0;
}

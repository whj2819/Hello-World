/*
 * 内存指针仍存在,还有机会使用或释放.
 *
 *
 * 10 bytes in 1 blocks are still reachable in loss record 1 of 1
 * LEAK SUMMARY:
 * ==10942==    definitely lost: 0 bytes in 0 blocks
 * ==10942==    indirectly lost: 0 bytes in 0 blocks
 * ==10942==      possibly lost: 0 bytes in 0 blocks
 * ==10942==    still reachable: 10 bytes in 1 blocks
 * ==10942==         suppressed: 0 bytes in 0 blocks
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * HowTo: 将日志输出到指定网络中去.
 *      valgrind --log-socket=IP:port program
 *
 * 在另一端打开valgrind-listen 命令
 *
 */
char *p;
int main(int argc, const char *argv[])
{

    p = (char *)malloc(10);

    /* 释放掉就好了. */
    /* free(p); */

    return 0;
}


/*
 * --trace-children=yes
 * --trace-children-skip=patt1,patt2 参数测试.
 * --child-silent-after-fork=[yes|no] 不显示fork调用产生的子进程的日志信息.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/prctl.h>


int main(int argc, const char *argv[])
{
    pid_t pid;

    prctl(PR_SET_NAME,(char *)"master");
    pid = fork();
    if (pid < 0) {
        printf("fork error");
    } else if (0 == pid) {
        prctl(PR_SET_NAME,(char *)"slave");
        printf("This is child \n");

        int a[5];
        if (0 == a[5]) {
            a[3] = 0;
        }
    } else {
        char *p = (char *)malloc(10);
        printf("This is parent\n");
    }

    printf("hello world\n"); 

    return 0;
}

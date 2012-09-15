#include "apue.h"
#include <termios.h>

int main(void)
{
    struct termios term;

    if (tcgetattr(STDIN_FILENO,&term) < 0) {
        err_sys("tcgetattr error");
    }

    //term.c_cflag &= ~CSIZE  ;
    //term.c_cflag |= CS5;
    switch (term.c_cflag & CSIZE) {
    case CS5:
        printf("5 bits/byte\n");
        break;
    case CS6:
        printf("6 bits/byte\n");
        break;
    case CS7:
        printf("7 bits/byte\n");
        break;
    case CS8:
        printf("8 bits/byte\n");
        break;
    default:
        printf("unknow bits/byte\n");
        break;
    }

    term.c_cflag &= ~CSIZE  ;
    term.c_cflag |= CS8;


    if (tcsetattr(STDIN_FILENO,TCSANOW,&term) < 0) {
        err_sys("tcsetattr error");
    }

    return 0;
}

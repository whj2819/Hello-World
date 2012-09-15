#include <stdio.h>
#include <unistd.h>
#include <termios.h>


int main(void)
{
    struct termios term;

    if (tcgetattr(STDOUT_FILENO,&term) < 0){
        printf("tcgetattr error\n");
    }

    term.c_cflag &= ECHO;
    term.c_cflag |= ECHO;

    if (tcsetattr(STDOUT_FILENO,TCSANOW,&term) < 0){
        printf("tcsetattr error\n");
    }

    return 0;
}

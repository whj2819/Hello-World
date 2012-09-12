#include "apue.h"
#include <termios.h>
#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif

#ifdef LINUX
#define OPTSTR "+d:einv"
#else
#define OPTSTR "d:einv"
#endif


static void set_noecho(int);
void do_driver(char *);
void loop(int,int);


int main(int argc,char *argv)
{
    int fdm,c,ignoreeof;
    int interactive,noecho,verbose;
    pid_t pid;
    char *driver;
    char slave_name[20];
    struct termios orig_termios;
    struct winsize size;

    interactive = isatty(STDIN_FILENO);


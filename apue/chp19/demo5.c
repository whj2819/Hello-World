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
    ignoreeof = 0;
    verbose = 0;
    driver = NULL;

    opterr = 0;

    while (( c = getopt(argc,argv,OPTSTR)) != EOF) {

        switch (c) {
        case 'd':
            driver = optarg;
            break;
        case 'e':
            noecho = 1;
            break;
        case 'i':
            ignoreeof = 1;
            break;
        case 'n':
            interactive = 0;
            break;
        case 'v':
            break;
        case '?':
            break;

    }


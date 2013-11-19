#include <stdio.h>
#include <unistd.h>
#include <getopt.h>


void
usage(void)
{
    printf("help me ! \n");
}


int main(int argc, char *argv[])
{
    int ch, i;
    char *arg = NULL;

    while ((ch = getopt(argc, argv, "M:N:")) != -1 ) {
        switch(ch) {
        case 'M':
            arg = optarg;
            printf("[%s] \n", arg);
            printf("-%d- \n", optind);
            printf("+%d+ \n", argc);
            break;
        case 'N':
                break;
        default:
                usage();
                break;
        }
    }
    for (i = 0; i < argc; i++) {
        printf("argv[%d] %s\n", i, argv[i]);
    }
    printf("\n");
    
    return 0;
}

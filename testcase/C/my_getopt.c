#include <stdio.h>
#include <unistd.h>


int main(int argc, const char *argv[])
{
    int ch = 0;

    printf("optind = %d \n", optind);
    while ( (ch = getopt(argc, argv, "a:")) != -1) {
        /* printf("optind = %d \n", optind); */
        switch (ch) {
            case 'a':
                printf("option a\n");
                printf("optarg = %s \n", optarg);
                break;
            default:
                break;
        }

    }
    printf("%d \n", ch);

    return 0;
}

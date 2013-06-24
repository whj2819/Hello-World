#include <stdio.h>
#include <sys/mman.h>
//#include <sys/types.h>
//#include <sys/stat.h>

typedef struct {
    char name[4];
    int age;
}people;

int
main(int argc, char *argv[])
{
    int i;
    people *p_map;
    char temp;

    p_map = (people *)mmap(
                          NULL,sizeof(people) * 10,
                          PROT_READ | PROT_WRITE,
                          MAP_SHARED | MAP_ANONYMOUS,
                          -1,
                          0
                       );

    if (fork() == 0) {
        sleep(2);
        for (i=0; i<5; i++)
            printf("child read: the %d people's age is %d\n",
                    i+1,(*(p_map+i)).age);
        (*p_map).age = 100;
        munmap(p_map,sizeof(people) * 10);
        exit();
    }

    return 0;
}



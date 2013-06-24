#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct {
    char name[4];
    int age;
}people;


int
main(int argc, char *argv[])
{
    int fd,i;
    int pagesize,offset;
    people *p_map;

    pagesize = sysconf(_SC_PAGESIZE);
    printf("pagesize is:[%d] \n",pagesize);

    fd = open(argv[1],O_CREAT|O_RDWR|O_TRUNC,00777);
    lseek(fd,pagesize * 2 -100,SEEK_SET);
    write(fd,"",1);
    offset = pagesize;

    p_map = (people *)mmap(
                            NULL,
                            pagesize * 3,
                            PROT_READ | PROT_WRITE,
                            MAP_SHARED,
                            fd,
                            offset
                       );
    close(fd);

    for (i=1; i<10; i++) {
        (p_map+pagesize/sizeof(people)*i -2)->age = 100;
        printf("access page %d over \n",i);

        (p_map+pagesize/sizeof(people)*i -1)->age = 100;
        printf("access page %d edge over,now begin to access page %d \n",i,i+1);

        (p_map+pagesize/sizeof(people)*i )->age = 100;
        printf("access page %d over \n",i+1);
    }

    munmap(p_map,sizeof(people) * 10);


    return 0;
}

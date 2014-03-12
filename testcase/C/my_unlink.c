#include  <stdio.h> 
#include  <stdlib.h> 
#include  <sys/time.h> 
#include  <sys/resource.h> 
#include  <string.h>
#include  <unistd.h> 
#include  <sys/stat.h>
#include  <sys/types.h>
#include  <fcntl.h>


/*
 * 
 * 理解unlink 与连接数.
 *
 *
 */
int main(int argc, const char *argv[])
{
    struct stat buf;
    int fd;

    memset( &buf, 0, sizeof(struct stat) );

    stat("tmp.txt", &buf);
    printf("11 link = %d \n", buf.st_nlink);

    fd = open("tmp.txt", O_RDONLY);
    stat("tmp.txt", &buf);
    printf("22 link = %d \n", buf.st_nlink);

    close(fd);
    stat("tmp.txt", &buf);
    printf("33 link = %d \n", buf.st_nlink);

    link("tmp.txt", "tmp02.txt");
    stat("tmp.txt", &buf);
    printf("44 link = %d \n", buf.st_nlink);

    unlink("tmp02.txt");
    stat("tmp.txt", &buf);
    printf("55 link = %d \n", buf.st_nlink);

    fd = open("tmp.txt", O_RDONLY);
    stat("tmp.txt", &buf);
    printf("22 link = %d \n", buf.st_nlink);

    unlink("tmp.txt");
    fstat(fd, &buf);
    printf("77 link = %d \n", buf.st_nlink);

    close(fd);
    return 0;
}


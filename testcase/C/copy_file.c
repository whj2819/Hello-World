#include <stdio.h>
#include <stdlib.h>


int
copy_file(const char *src_file_name,
        const char *dst_file_name)
{
    char *src = (char *)src_file_name;
    char *dst = (char *)dst_file_name;
    char buf[128] ={0};
    FILE *src_fd, *dst_fd;
    int n;

    src_fd = fopen(src,"r");
    if (src_fd == NULL)
        printf("can't open file %s \n",src);
    
    dst_fd = fopen(dst,"w");
    if (dst_fd == NULL)
        printf("can't open file %s \n",dst);
  

    while ((n = fread(buf,10,1,src_fd) > 0) ) {
        fwrite(buf,10,1,dst_fd);
    }

    fclose(dst_fd);
    fclose(src_fd);
    return 0;
}

void
file_start(void)
{
    FILE *fd, *tmp_fd;
    char buf[] = "file start:";
    char d[128] = {0};

    fd = fopen("a.file","r+");
    if (fd == NULL) {
        printf("can't open file \n");
        exit(-1);
    }

    tmp_fd = fopen("tmp.file","a+");
    if (tmp_fd == NULL)
        printf("can't open file \n");

    fwrite(buf,sizeof(char), sizeof(buf),tmp_fd);
    while( fread(d, sizeof(char), sizeof(d), fd) >0)
        fwrite(d, sizeof(char), sizeof(d), tmp_fd);

    fclose(fd);
    fclose(tmp_fd);

    rename("tmp.file","a.file");
}

int
main(void)
{
   // const char *s = "filea.c";
    //const char *d = "fileb.c";

    //copy_file(s, d);
    file_start();


    return 0;
}


#include <stdio.h>
#pragma pack(1)

struct foo_t {
    char a;
    char b[25];
    int c;
};

#pragma pack()

int
main(int argc, char *argv)
{
    FILE *fp = NULL;
    struct foo_t foo_1 = {12457,"test foo_1",75421};
    struct foo_t foo_2 = {36098,"test foo_2",89063};


    fp = fopen("foo.dat","wb+");
    if (fp == NULL)
        printf("error in open foo.dat \n");

    fwrite(&foo_1,sizeof(foo_1),1,fp);
    fwrite(&foo_2,sizeof(foo_2),1,fp);

    fclose(fp);

    return 0;
}

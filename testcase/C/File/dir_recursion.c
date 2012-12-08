#include   <stdio.h>  
#include <stdlib.h>
#include <string.h>

#include   <dirent.h>  
#include   <sys/types.h>  
#include   <sys/stat.h>  
#include <unistd.h>

#define PATHNAME 50

void   dir_scan(char *path, char *file);  
static int   count = 0;  

int 
main(int argc, char **argv)  
{  
    struct   stat   s;  

    if (argc != 2) {  
        printf("one   direction   requried\n");  
        exit(1);  
    }  
    if (lstat(argv[1],   &s) < 0) {  
        printf("lstat   error\n");  
        exit(2);  
    }  
    if (!S_ISDIR(s.st_mode)) {  
        printf("%s   is   not   a   direction   name\n",   argv[1]);  
        exit(3);  
    }  
    dir_scan("",argv[1]);  
    printf("total:   %d   files\n",   count);  

    exit(0);  
}  

void
dir_scan(char *path, char *file)  
{  
    struct   stat   s;  
    DIR           *dir;  
    struct   dirent   *dt;  
    char   dirname[PATHNAME];  

    memset(dirname,0,PATHNAME*sizeof(char));  
    strcpy(dirname,path);  

    if(lstat(file, &s) < 0) {  
        printf("lstat   error\n");  
    }  

    if(S_ISDIR(s.st_mode)){  
        strcpy(dirname+strlen(dirname),   file);  
        strcpy(dirname+strlen(dirname),   "/");  
        if ((dir = opendir(file)) == NULL) {  
            printf("opendir error\n");  
            exit(4);  
        }  
        if (chdir(file) < 0) {  
            printf("chdir   error\n");  
            exit(5);  
        }  
        while((dt = readdir(dir)) != NULL) {  
            if (dt->d_name[0] == '.') {  
                continue;  
            }  
            dir_scan(dirname,   dt->d_name);  
        }  
        if (chdir("..") < 0) {
            printf("chdir error");
            exit(6);
        }
    } else {  
        printf("%s%s\n",   dirname,   file);  
        count++;  
    }  
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int
main(int argc, char *argv[])
{
    char *error = "ERROR:";
    char *error_message = "not enough memory";

    char *buffer = (char *)malloc(strlen(error) + strlen(error_message) +1);

    strcpy(buffer,error);
    strcat(buffer,error_message);

    printf("[%s] \n",buffer);
    printf("[%s] \n",error);
    printf("[%s] \n",error_message);

    return 0;

}

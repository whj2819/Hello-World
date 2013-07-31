#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
format(char *buffer,size_t size,
        const char *name,size_t quantity,size_t weight)
{

    snprintf(buffer,size,"Item:%s Quantity:%u Weight:%u",
            name,quantity,weight);

    return buffer;
}


/*
 *input:"hello world abc"
 *
 *output: "cba dlrow olleh"
 */
void
reverse(char *s)
{
    int i, tmp;
    int len = strlen(s);

    for(i=0; i<len/2; i++) {
        tmp = s[len - i -1];
        s[len - i -1]  = s[i];
        s[i] = tmp;
    }
}

int
main(void)
{
    char s[] = "hello world abc";

    reverse(s);
    printf("%s \n", s);
    return 0;
}



#if 0
int
main(int argc, char *argv[])
{
    char buffer[128] = {0};

    printf("%s \n",format(buffer,sizeof(buffer), "Axle",25,45));
    return 0;

}
#endif

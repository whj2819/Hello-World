#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



char *
my_strcpy(char *dest, const char *src)
{
    char *tmp = dest;

    assert(dest != NULL);
    assert(src != NULL);

    while ( (*dest++ = *src++) != '\0') {
        ;
    }

    return tmp;
}


char *
my_strncpy(char *dest, const char *src, size_t n)
{
    char *tmp = dest;
    int i; 

    assert(dest != NULL);
    assert(src != NULL);
    
    for (i = 0; i < n; i++) {
        *(dest + i) = *(src + i);
    }
    *(dest + i) = '\0';

    return tmp;
}

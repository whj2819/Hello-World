/*
 * 删除重复的字符串
 *
 * input: abcdabcdabcd
 * output: abcd
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 100

static char *
remove_duplicate_characters(const char *s, int len)
{
    int i, j;
    int flag = 0, k=0;
    char *s2;

    s2 = (char *)malloc(BUFSIZE * sizeof(char) + 1);
    for (i=0; s[i] != '\0'; i++) {
        flag = 1;
        for (j=0; j<k; j++) {
            if (s[i] == s2[j]) {
                flag = 0;
                break;
            }
        }

        if (flag)
            s2[k++] = s[i];
    }
    s2[k] = '\0';

    return s2;
}


int
main(void)
{
    char s1[BUFSIZE] = "dcbaabcdacbde"; // output:abcd
    char *p = NULL;
    int len = strlen(s1);

    p = remove_duplicate_characters(s1, len);
    printf("%s \n", p); 

    free(p);
    p = NULL;

    return 0;
}

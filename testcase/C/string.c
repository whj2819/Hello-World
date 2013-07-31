#include <stdio.h>
#include <string.h>
#include <ctype.h>
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


static void
reverse_word(char *p, char *q)
{
    char t;

    while (p < q) {
        t = *p;
        *p++ = *q;
        *q-- = t;
    }
}

void
fun(char *s)
{
    char *p, *q;

    p= s; q=s;
    while(*q != '\0') {
        if (isspace(*q)) {
            reverse_word(p, q-1);
            q++;
            p = q;
        } else {
            q++;
        }
    }
    reverse_word(p, q-1); //最后一个单词
    //reverse_word(s, q-1);// ====> ULLY FVs ast
}

int
main(void)
{
    char s[] = "ast FVs ULLY"; // =====>"tsa sVF YLLU"

    fun(s);

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

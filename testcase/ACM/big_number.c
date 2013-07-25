#include <stdio.h>
#include <string.h>

#define MAX_SIZE (400)

static char answer[MAX_SIZE + 1] = {0};
static void
print_num(char *s, int len)
{
    int i;

    for (i=len - 1; i>=0; i--)
        printf("%d", s[i]);
    printf("\n");
}

static void
reverse(char *s, int len)
{
    int i, tmp;

    for (i=0; i<len/2; i++) {
        tmp = s[len-i-1];
        s[len-i -1] = s[i];
        s[i] = tmp; 
    }
}

void
big_add(char *a, char *b)
{
    int len, len1, len2;
    int i, tmp;
    char carry = 0;

    len1 = strlen(a);
    len2 = strlen(b);
    if (len1 > len2)
        len = len1;
    else
        len = len2;

    reverse(a, len1);
    reverse(b, len2);
    for (i=0; i<len; i++) {
        if (a[i] == 0  || b[i] == 0)
            tmp = a[i] + b[i] + carry - '0';
        else
            tmp = a[i] + b[i] + carry - '0' - '0';
        carry = tmp / 10;
        answer[i] = tmp % 10;
    }

    if (1 == carry) /* 最高位有进位 */
        answer[len] = 1;

    print_num(answer, len);
}

void
big_sub(char *a, char *b)
{
    printf("big_sub \n");
}

void (*func)(char *, char *);

int
main(void)
{
    int count;
    char a[MAX_SIZE] = {0}; 
    char b[MAX_SIZE] = {0}; 
    char c;
    
    scanf("%d", &count);
    getchar();
    while(count--) {
        scanf("%s %c %s", a, &c, b);
        getchar();
        switch(c) {
            case '+':
                func = big_add;
                break;
            case '-':
                func = big_sub;
                break;
            default:
                printf("unknow operation! \n");
                break;
        }
        func(a, b);
    }
    return 0;
}

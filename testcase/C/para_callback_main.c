#include <stdio.h>
#include "para_callback.h"

void
say_hello(void *str)
{
    printf("Hello %s\n", (const char *)str);
}

int
main(void)
{
    repeat_three_times(say_hello, "Guys");

    return 0;
}

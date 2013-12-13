
extern void eprintf(const char *format, ...)\
           __attribute__((format(printf, 1, 2)));


void
foo()
{
    eprintf("s = %s\n", 5);
    /* eprintf("n = %d, %d, %d \n", 1, 2); */

}


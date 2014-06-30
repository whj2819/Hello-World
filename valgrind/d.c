#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void funca();
void funcb();
void funcc();
void my_sleep();

void funca()
{
    my_sleep();
    funcb();

}

void funcb()
{
    my_sleep();
    my_sleep();
    my_sleep();
    my_sleep();

}

void funcc()
{
    my_sleep();
}

void
my_sleep()
{
    int i, j;

    for (i = 0; i < 1024; i++) {
        for (j = 0; j < 9256; j++) {
            ; 
        } 
    } 
}



int main(int argc, const char *argv[])
{


    funca();
    funcc();

    
    return 0;
}

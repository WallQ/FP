#include <stdio.h>

void increment(int *x)
{
    *x = *x + 1;
}

int main(int argc, char *argv[])
{
    int value = 0;

    increment(&value);

    printf("The value is %d", value);

    return 0;
}
#include <stdio.h>

void foobar(int value, int *pValue)
{
    printf("The value of value inside foobar is %d\n", value);
    printf("The address value of value inside foobar is %p\n", &value);

    printf("The value of pointer inside foobar is %d\n", *pValue);
    printf("The address value of pointer inside foobar is %p\n", pValue);

    value++;
    (*pValue)++;
}

int main(int argc, char *argv[])
{
    int value = 0;

    printf("The value of value is %d\n", value);
    printf("The address value of value is %p\n", &value);

    foobar(value, &value);

    printf("The value of value is %d\n", value);

    return 0;
}
#include <stdio.h>

#define ROWS 3
#define COLS 3

int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }

    return num * factorial(num - 1);
}

int main(int argc, char *argv[])
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The factorial of the number is: %d\n", factorial(num));
}

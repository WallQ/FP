#include <stdio.h>

void sum(int num1, int num2, int *resultado)
{
    *resultado = num1 + num2;
}

int main(int argc, char *argv[])
{
    int num1, num2, result;

    printf("Enter the 1st value\n");
    scanf("%d", &num1);
    printf("Enter the 2nd value\n");
    scanf("%d", &num2);

    sum(num1, num2, &result);

    printf("The result is %d", result);

    return 0;
}
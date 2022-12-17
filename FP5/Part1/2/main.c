#include <stdio.h>

float sum(float a, float b)
{
    return a + b;
}

float sub(float a, float b)
{
    return a - b;
}

float mult(float a, float b)
{
    return a * b;
}

float div(float a, float b)
{
    return a / b;
}

int main(int argc, char *argv[])
{
    float num1, num2;

    printf("Enter the 1st number: ");
    scanf("%f", &num1);

    printf("Enter the 2nd number: ");
    scanf("%f", &num2);

    printf("The sum of the two numbers is: %0.2f\n", sum(num1, num2));
    printf("The subtraction of the two numbers is: %0.2f\n", sub(num1, num2));
    printf("The multiplication of the two numbers is: %0.2f\n", mult(num1, num2));
    printf("The division of the two numbers is: %0.2f\n", div(num1, num2));
}

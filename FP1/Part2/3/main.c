#include <stdio.h>

int main(int argc, char *argv[])
{
    int num1, num2;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);

    printf("Enter the 2nd number: ");
    scanf("%d", &num2);

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    printf("The values of the swap two numbers is: num1 = %d, num2 = %d", num1, num2);

    return 0;
}
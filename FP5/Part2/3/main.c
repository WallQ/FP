#include <stdio.h>
#include "intLib.h"

int main(int argc, char *argv[])
{
    int num1, num2;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);

    printf("Enter the 2nd number: ");
    scanf("%d", &num2);

    printf("The max value of the two numbers is %.2f\n", maxNum(num1, num2));
    printf("The min value of the two numbers is %.2f\n", minNum(num1, num2));
}
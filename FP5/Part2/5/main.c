#include <stdio.h>
#include "menu.h"
#include "intLib.h"

int main(int argc, char *argv[])
{
    int num1, num2, menuOption;

    do
    {
        menuOption = readMenuOption();

        if (menuOption != 0)
        {
            printf("Enter the 1st number: ");
            scanf("%d", &num1);
            printf("Enter the 2nd number: ");
            scanf("%d", &num2);
        }

        switch (menuOption)
        {
            case 1:
                printf("The sum of the two numbers is %2.f\n", sum(num1, num2));
                break;

            case 2:
                printf("The subtraction of the two numbers is %2.f\n", subtract(num1, num2));
                break;

            case 3:
                printf("The multiplication of the two numbers is %2.f\n", multiply(num1, num2));
                break;

            case 4:
                printf("The division of the two numbers is %2.f\n", divide(num1, num2));
                break;

            case 5:
                printf("The max number of the two numbers is %2.f\n", maxNum(num1, num2));
                break;

            case 6:
                printf("The min number of the two numbers is %2.f\n", minNum(num1, num2));
                break;

            case 7:
                printf("The potency of the two numbers is %2.f\n", findPotency(num1, num2));
                break;

            case 0:
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (menuOption != 0);
}
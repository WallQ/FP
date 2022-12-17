#include <stdio.h>

int main(int argc, char *argv[])
{
    int num1, num2, num3;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);
    printf("Enter the 2nd number: ");
    scanf("%d", &num2);
    printf("Enter the 3rd number: ");
    scanf("%d", &num3);

    if (num1 < num2 && num1 < num3)
    {
        printf("The lowest number is the 1st number (%d).", num1);
    }
    else if (num2 < num1 && num2 < num3)
    {
        printf("The lowest number is the 2nd number (%d).", num2);
    }
    else if (num3 < num1 && num3 < num2)
    {
        printf("The lowest number is the 3rd number (%d).", num3);
    }
    else
    {
        printf("The numbers are equal.");
    }

    return 0;
}
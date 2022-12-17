#include <stdio.h>

int main(int argc, char *argv[])
{
    int num1, num2;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);
    printf("Enter the 2nd number: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("The 1st number (%d) is greater than the 2nd number (%d).", num1, num2);
    }
    else
    {
        printf("The 2nd number (%d) is greater than the 1st number (%d).", num2, num1);
    }

    return 0;
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    float num1, num2, num3;

    printf("Enter the 1st number: ");
    scanf("%f", &num1);

    printf("Enter the 2nd number: ");
    scanf("%f", &num2);

    printf("Enter the 3rd number: ");
    scanf("%f", &num3);

    printf("The average of the three numbers is: %f\n", (num1 + num2 + num3) / 3.0);
    printf("The weighted average of the three numbers is: %f\n", (num1 * 0.2) + (num2 * 0.3) + (num3 * 0.5) / 1.0);

    return 0;
}
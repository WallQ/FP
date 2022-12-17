#include <stdio.h>

int main(int argc, char *argv[])
{
    int num1, num2;
    char op;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);

    printf("Enter the 2nd number: ");
    scanf("%d", &num2);

    printf("Enter the operator: ");
    scanf(" %c", &op);

    switch (op)
    {
        case '+':
            printf("The sum is %d", num1 + num2);
            break;
        case '-':
            printf("The subtraction is %d", num1 - num2);
            break;
        case '*':
            printf("The multiplication is %d", num1 * num2);
            break;
        case '/':
            printf("The division is %f", (float)num1 / num2);
            break;

        default:
            printf("Invalid operator");
            break;
    }

    return 0;
}
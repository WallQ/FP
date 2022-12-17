#include <stdio.h>

int main(int argc, char *argv[])
{
    int numb1, numb2;
    char operator, choise;

    do
    {
        printf("Enter the 1st number: ");
        scanf("%d", &numb1);

        printf("Enter the 2nd number: ");
        scanf("%d", &numb2);

        printf("Enter the operator: ");
        scanf(" %c", &operator);

        switch (operator)
        {
            case '+':
                printf("%d + %d = %d\n", numb1, numb2, numb1 + numb2);
                break;
            case '-':
                printf("%d - %d = %d\n", numb1, numb2, numb1 - numb2);
                break;
            case '*':
                printf("%d * %d = %d\n", numb1, numb2, numb1 * numb2);
                break;
            case '/':
                printf("%d + %d = %f\n", numb1, numb2, (float)numb1 / numb2);
                break;
            default:
                printf("%d + %d = %d\n", numb1, numb2, numb1 + numb2);
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choise);
    } while (choise != 'n' && choise != 'N');

    return 0;
}
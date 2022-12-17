#include <stdio.h>

int main(int argc, char *argv[])
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    switch (number)
    {
        case 1:
            printf("The value of the number %d is one.", number);
            break;
        case 2:
            printf("The value of the number %d is two.", number);
            break;
        case 3:
            printf("The value of the number %d is three.", number);
            break;
    }

    return 0;
}
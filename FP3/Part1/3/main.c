#include <stdio.h>

int main(int argc, char *argv[])
{
    char option;

    printf("U-Uppercase\nL-Lowercase\n");
    printf("Enter an option: ");
    scanf(" %c", &option);

    switch (option)
    {
        case 'U':
        case 'u':
            for (size_t i = 65; i < 91; i++)
            {
                printf("\n %c", i);
            }
            break;
        case 'L':
        case 'l':
            for (size_t i = 97; i < 123; i++)
            {
                printf("\n %c", i);
            }
            break;
        default:
            printf("Invalid option!");
    }

    return 0;
}
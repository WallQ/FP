#include <stdio.h>

int main(int argc, char *argv[])
{
    int option;

    do
    {
        printf("1-Option 1\n2-Option 2\n3-Option 3\n0-Option 0\n");
        printf("Enter your choice: ");
        scanf(" %d", &option);
    } while (option != 1 && option != 2 && option != 3 && option != 0);

    for (size_t i = 1; i < 6; ++i)
    {
        for (size_t j = 1; j < i; ++j)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
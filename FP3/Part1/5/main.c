#include <stdio.h>

int main(int argc, char *argv[])
{
    int number;

    do
    {
        printf("Enter an number: ");
        scanf("%d", &number);
    } while (number <= 0);

    for (size_t i = number; i > 0; i--)
    {
        if (i % 2 != 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
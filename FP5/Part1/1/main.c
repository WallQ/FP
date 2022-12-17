#include <stdio.h>

void printStars(int number)
{
    for (size_t i = 0; i < number; i++)
    {
        printf("*");
    }
}

int main(int argc, char *argv[])
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printStars(number);
}
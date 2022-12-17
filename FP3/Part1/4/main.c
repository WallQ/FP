#include <stdio.h>

int main(int argc, char *argv[])
{
    int number, average = 0, count = 0;

    do
    {
        printf("Enter an number: ");
        scanf("%d", &number);
        if (number != 0)
        {
            average += number;
            count++;
        }
    } while (number != 0);

    printf("The average of %d is: %d", count, average / count);

    return 0;
}
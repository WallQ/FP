#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    int numbers[10], maxValue = INT_MIN;

    for (size_t i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (size_t i = 0; i < 10; i++)
    {
        if ((numbers[i] % 2 == 0) && numbers[i] > maxValue)
        {
            maxValue = numbers[i];
        }
    }

    if (maxValue == INT_MIN)
    {
        printf("No even numbers were entered.");
    }
    else
    {
        printf("The largest even number is %d.", maxValue);
    }

    return 0;
}
#include <stdio.h>
#include <limits.h>

int *findMax(int data[])
{
    int max = INT_MIN;

    for (size_t i = 0; i < 10; i++)
    {
        if (data[i] > max)
        {
            max = i;
            printf("Test: %p\n", &data[i]);
        }
    }

    return &data[max];
}

int main(int argc, char *argv[])
{
    int array[10];

    for (size_t i = 0; i < 10; i++)
    {
        printf("Enter a number for %d: \n", i + 1);
        scanf("%d", &array[i]);
    }

    int *max = findMax(array);

    printf("The largest number is %p\n", max);

    return 0;
}
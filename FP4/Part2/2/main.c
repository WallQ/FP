#include <stdio.h>

#define ARRAY_SIZE 10

int main(int argc, char *argv[])
{
    int numbers[ARRAY_SIZE] = {0};

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        if (i % 2 == 0)
        {
            for (size_t j = 0; j < ARRAY_SIZE; j++)
            {
                if (numbers[j] == 0)
                {
                    numbers[j] = i;
                    break;
                }
            }
        }
    }

    printf("The even numbers are: \n");
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
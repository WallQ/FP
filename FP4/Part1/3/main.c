#include <stdio.h>

int main(int argc, char *argv[])
{
    int matrix[4][5], findNumber, count;

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 5; col++)
        {
            printf("Enter element [%d,%d] : ", row + 1, col + 1);
            scanf("%d", &matrix[row][col]);
        }
    }

    printf("Enter the number to find : ");
    scanf("%d", &findNumber);

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 5; col++)
        {
            if (matrix[row][col] == findNumber)
            {
                count++;
            }
        }
    }

    printf("The number %d is found %d times in the matrix.\n", findNumber, count);

    return 0;
}
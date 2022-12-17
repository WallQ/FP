#include <stdio.h>

int main(int argc, char *argv[])
{
    int matrix[3][3], minNumber = 99999, maxNumber = -99999;

    for (size_t row = 0; row < 3; row++)
    {
        for (size_t col = 0; col < 3; col++)
        {
            printf("Enter element [%d,%d] : ", row + 1, col + 1);
            scanf("%d", &matrix[row][col]);
            if (matrix[row][col] > maxNumber)
            {
                maxNumber = matrix[row][col];
            }
            if (matrix[row][col] < minNumber)
            {
                minNumber = matrix[row][col];
            }
        }
    }

    printf("The maximum number is: %d\n", maxNumber);
    printf("The minimum number is: %d\n", minNumber);

    for (size_t row = 0; row < 3; row++)
    {
        for (size_t col = 0; col < 3; col++)
        {
            printf("%d", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}
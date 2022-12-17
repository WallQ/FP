#include <stdio.h>

#define ROWS 3
#define COLS 3

void sumMatrixs(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS])
{
    int sum[ROWS][COLS];

    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            sum[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }

    printf("Sum of two matrices: \n");
    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            printf("%d ", sum[row][col]);
        }
        printf("\n");
    }
}

void sumMatrixElements(int matrix[ROWS][COLS])
{
    int sum = 0;

    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            sum += matrix[row][col];
        }
    }

    printf("Sum of all elements in matrix: %d\n", sum);
}

int main(int argc, char *argv[])
{
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS];

    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            printf("Enter the value for the 1st matrix [%d][%d]: ", row, col);
            scanf("%d", &matrix1[row][col]);
        }
    }

    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            printf("Enter the value for the 2nd matrix [%d][%d]: ", row, col);
            scanf("%d", &matrix2[row][col]);
        }
    }

    sumMatrixs(matrix1, matrix2);
    sumMatrixElements(matrix1);
    sumMatrixElements(matrix2);
}

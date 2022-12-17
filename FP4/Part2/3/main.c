#include <stdio.h>

#define ROWS 3
#define COLS 3

int main(int argc, char *argv[])
{
    int matrix[ROWS][COLS], matrixT[ROWS][COLS];

    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            printf("Enter value for row %zu, column %zu: ", row, col);
            scanf("%d", &matrix[row][col]);
        }
    }

    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            matrixT[row][col] = matrix[col][row];
        }
    }

    printf("This is the matrix: \n");
    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            printf("%d\t", matrix[row][col]);
        }
        printf("\n");
    }

    printf("This is the transpose matrix: \n");
    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            printf("%d\t", matrixT[row][col]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

#define ROWS 4
#define COLS 4

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
        for (size_t col = 0; col < COLS - row; col++)
        {
            int ptr = matrix[row][col];
            matrix[row][col] = matrix[COLS - 1 - col][ROWS - 1 - row];
            matrix[COLS - 1 - col][ROWS - 1 - row] = ptr;
        }
    }
    for (size_t row = 0; row < ROWS / 2; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            int ptr = matrix[row][col];
            matrix[row][col] = matrix[ROWS - 1 - row][col];
            matrix[ROWS - 1 - row][col] = ptr;
        }
    }

    printf("This is the matrix rotated 90 degrees: \n");
    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            printf("%d\t", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}
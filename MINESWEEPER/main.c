#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5
#define PERCENTAGE 0.3

void printMatrix(int matrix[ROW][COL]) {
    for (int row = 0; row < ROW; ++row) {
        printf("\n");
        for (int col = 0; col < COL; ++col) {
            printf("%d\t", matrix[row][col]);
        }
    }
    printf("\n");
}

int generateRandomNumber() {
    return rand() % 4 + 0;
}

int verifyEmptyPosition(int matrix[ROW][COL], int row, int col) {
    return matrix[row][col] == 0;
}

int getValue(char message[]) {
    int value;

    do {
        printf("%s", message);
        scanf("%d", &value);
    } while (value < 0 || value > 4);

    return value;
}

int verifyLose(int matrix[ROW][COL], int row, int col) {
    return matrix[row][col] == -1;
}

int main() {
    int matrix[ROW][COL], percentageMatrix, randomRow, randomCol, choiceRow, choiceCol;

    srand(time(NULL)) ;

    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            matrix[row][col] = 0;
        }
    }

    printMatrix(matrix);

    percentageMatrix = (int)(25 * PERCENTAGE);

    for (int i = 0; i < percentageMatrix; ++i) {
        do {
            randomRow = generateRandomNumber();
            randomCol = generateRandomNumber();
        } while (verifyEmptyPosition(matrix, randomRow, randomCol) != 1);
        matrix[randomRow][randomCol] = -1;
    }

    printMatrix(matrix);

    do {
        choiceRow = getValue("Enter the ROW: \n");
        choiceCol = getValue("Enter the COLUMN: \n");
    } while (verifyLose(matrix, choiceRow, choiceCol) != 1);

    printf("You stepped on a mine!");

    return 0;
}

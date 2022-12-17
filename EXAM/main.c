#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

int getValue(char message[]) {
    int value;

    do {
        printf("%s", message);
        scanf("%d", &value);
    } while (value < 0 || value >= 3);

    return value;
}

void printMatrix(int matrix[ROW][COL]) {
    for (int row = 0; row < ROW; ++row) {
        printf("\n");
        for (int col = 0; col < COL; ++col) {
            printf("%d\t", matrix[row][col]);
        }
    }
    printf("\n");
}

int verifyEmptyPosition(int matrix[ROW][COL], int row, int col) {
    if (matrix[row][col] == -1) {
        return 1;
    }

    return 0;
}

int verifyVictory(int matrix[ROW][COL], int player) {
    int countLines = 0, countColumns = 0, countDiagonal1 = 0, countDiagonal2 = 0;

    for (int row = 0; row < ROW; ++row) {
        countLines = countColumns = 0;

        for (int col = 0; col < COL; ++col) {
            countLines += (matrix[row][col] == player);
            countColumns += (matrix[col][row] == player);
        }

        if (countColumns == 3 || countLines == 3) {
            return 1;
        }

        countDiagonal1 += (matrix[row][row] == player);
        countDiagonal2 += (matrix[row][abs(row - 3) - 1] == player);
    }

    if (countDiagonal1 == 3 || countDiagonal2 == 3) {
        return 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    int matrix[ROW][COL], rowChoice, colChoice, player = 0, countMoves = 0, victory = 0;

    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            matrix[row][col] = -1;
        }
    }

    printMatrix(matrix);

    do {
        printf("Player: %d (Move: %d)\n", player, countMoves);

        do {
            rowChoice = getValue("Enter the ROW: \n");
            colChoice = getValue("Enter the COLUMN: \n");
        } while (verifyEmptyPosition(matrix, rowChoice, colChoice) != 1);

        matrix[rowChoice][colChoice] = player;

        printMatrix(matrix);

        victory = verifyVictory(matrix, player);

        if (victory != 1) {
            switch (player) {
                case 0:
                    player = 1;
                    break;
                case 1:
                    player = 0;
                    break;
            }
        }

        ++countMoves;
    } while (countMoves < (ROW * COL) && victory != 1);

    if (victory == 1) {
        printf("The winner is the player %d in %d moves.", player, countMoves - 1);
    } else {
        printf("The match ended in a draw.");
    }

    return 0;
}

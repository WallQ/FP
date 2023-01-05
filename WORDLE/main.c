#include <stdio.h>

#define MAX_TRIES 5
#define WORD_SIZE 5
#define DICT_SIZE 5

void printMatrix(char matrix[MAX_TRIES][WORD_SIZE]) {
    for (int row = 0; row < MAX_TRIES; ++row) {
        printf("\n");
        for (int col = 0; col < WORD_SIZE; ++col) {
            printf("%c\t", matrix[row][col]);
        }
        printf("\n");
    }
}

int wordExist(char guess[WORD_SIZE + 1], char dict[DICT_SIZE][WORD_SIZE]) {
    int count = 0;

    for (int row = 0; row < MAX_TRIES; ++row) {
        count = 0;
        for (int col = 0; col < WORD_SIZE; ++col) {
            if (count == 4) return row;
            if (guess[col] == dict[row][col]) count++;
        }
    }

    return 0;
}

void printResult(int round, char tries[MAX_TRIES][WORD_SIZE], char result[MAX_TRIES][WORD_SIZE]) {
    printf("ROUND %d: ", round + 1);
    for (int col = 0; col < WORD_SIZE; ++col) {
        printf("%c ", tries[round][col]);
    }
    printf("\t");
    for (int col = 0; col < WORD_SIZE; ++col) {
        printf("%c ", result[round][col]);
    }
    printf("\n");
}

int verifyVictory(int round, char result[MAX_TRIES][WORD_SIZE]) {
    int count = 0;

    for (int row = 0; row < MAX_TRIES; ++row) {
        count = 0;
        for (int col = 0; col < WORD_SIZE; ++col) {
            if (count == 4) return 1;
            if (result[row][col] == 'V') count++;
        }
    }

    return 0;
}

int main() {
    char tries[MAX_TRIES][WORD_SIZE], result[MAX_TRIES][WORD_SIZE], dict[DICT_SIZE][WORD_SIZE] = {"pizza", "sharp",
                                                                                                  "elite", "space",
                                                                                                  "label"}, word[
            WORD_SIZE + 1] = "space", guess[WORD_SIZE + 1];
    int round = 0, victory = 0, count = 0;

    for (int row = 0; row < MAX_TRIES; ++row) {
        for (int col = 0; col < WORD_SIZE; ++col) {
            tries[row][col] = '_';
            result[row][col] = '_';
        }
    }

    do {
        printf("Enter you guess: ");
        scanf("%s", guess);

        for (int col = 0; col < WORD_SIZE; ++col) {
            tries[round][col] = guess[col];
        }

        for (int col = 0; col < WORD_SIZE; ++col) {
            if (guess[col] == word[col]) {
                result[round][col] = 'V';
                continue;
            } else {
                for (int col1 = 0; col1 < WORD_SIZE; ++col1) {
                    if (guess[col] == word[col1]) {
                        result[round][col] = 'O';
                        break;
                    }
                }
            }
            if (result[round][col] != 'V' && result[round][col] != 'O' && result[round][col] == '_') result[round][col] = 'X';
        }

        printResult(round, tries, result);

        victory = verifyVictory(round, result);

        if (victory != 0) printf("Congratulations! You won on round %d ", round + 1);

        round++;
    } while (round < 5 && victory == 0);

    if (victory == 0) printf("Your attempts are over! Try it again!");

    return 0;
}

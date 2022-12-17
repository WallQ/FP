#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intLib.h"

int main(int argc, char *argv[])
{
    float students[30], sumGrades;

    srand(time(0));

    float randomNum = rand() % (29 - 0 + 1);

    printf("Random number: %d\n", (int)randomNum);

    for (size_t i = 0; i < (int)randomNum; i++)
    {
        do
        {
            printf("Enter student %d's grade: \n", i + 1);
            scanf("%f", &students[i]);
        } while (students[i] < 0 || students[i] > 20);
    }

    for (size_t i = 0; i < (int)randomNum; i++)
    {
        sumGrades += sum(students[i], 0);
    }

    printf("The average grade is: %.2f\n", divide(sumGrades, randomNum));
}
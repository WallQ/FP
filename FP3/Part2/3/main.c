#include <stdio.h>

int main(int argc, char *argv[])
{
    int number, guess, count;

    printf("Enter a number: ");
    scanf("%d", &number);

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > number)
            printf("Too high!\n");
        else if (guess < number)
            printf("Too low!\n");

        count++;
    } while (guess != number);

    printf("You guessed it in %d tries.\n", count);

    return 0;
}
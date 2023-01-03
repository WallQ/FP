#include "input.h"
#include <stdio.h>
#include <string.h>

void cleanInputBuffer()
{
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

int getInt(int minValue, int maxValue, char *message)
{
    int value;

    printf(message);

    while (scanf("%d", &value) != 1 || value < minValue || value > maxValue)
    {
        puts(INVALID_INPUT_MESSAGE);
        cleanInputBuffer();
        printf(message);
    }

    cleanInputBuffer();

    return value;
}

float getFloat(float minValue, float maxValue, char *message)
{
    float value;

    printf(message);

    while (scanf("%f", &value) != 1 || value < minValue || value > maxValue)
    {
        puts(INVALID_INPUT_MESSAGE);
        cleanInputBuffer();
        printf(message);
    }

    cleanInputBuffer();

    return value;
}

double getDouble(double minValue, double maxValue, char *message)
{
    double value;

    printf(message);

    while (scanf("%lf", &value) != 1 || value < minValue || value > maxValue)
    {
        puts(INVALID_INPUT_MESSAGE);
        cleanInputBuffer();
        printf(message);
    }

    cleanInputBuffer();

    return value;
}

char getChar(char *message)
{
    char value;

    printf(message);

    value = getchar();

    cleanInputBuffer();

    return value;
}

void getString(char *string, unsigned int size, char *message)
{
    printf(message);

    if (fgets(string, size, stdin) != NULL)
    {
        unsigned int len = strlen(string) - 1;

        if (string[len] == '\n')
        {
            string[len] = '\0';
        }
        else
        {
            cleanInputBuffer();
        }
    }
}
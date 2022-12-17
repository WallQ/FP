#include <stdio.h>

int length(char *str)
{
    int count = 0;

    for (size_t i = 0; i < *str; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        count++;
    }

    return count;
}

int main(int argc, char *argv[])
{
    char string[100];

    printf("Enter a string: ");
    scanf("%s", string);

    printf("Length of string: %d", length(string));

    return 0;
}
#include <stdio.h>
#include <string.h>

char *findChar(char *str, char ch)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            return &str[i];
        }
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    char string[100], ch;

    printf("Enter the value of the string: \n");
    scanf("%s", string);
    printf("Address value of string %p\n", &string);

    printf("Enter the value of the char: \n");
    scanf(" %c", &ch);

    printf("The address of the char is: %p", findChar(string, ch));

    return 0;
}
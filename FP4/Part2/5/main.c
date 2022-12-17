#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char text[26], temp;
    int length;

    printf("Enter a message to invert: \n");
    fgets(text, sizeof(text), stdin);

    // printf("The message reversed is: %s", strrev(text));

    length = strlen(text) - 1;

    for (size_t i = 0; i < length; i++)
    {
        temp = text[length];
        text[length] = text[i];
        text[i] = temp;
        length--;
    }

    printf("The message reversed is: %s", text);

    return 0;
}
#include <stdio.h>

void printFirst(char *str, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%c ", str[i]);
    }
}

int main(int argc, char *argv[])
{
    char string[100];
    int length;

    printf("Enter the value of the string: \n");
    scanf("%s", string);

    printf("Enter the value of the length: \n");
    scanf("%d", &length);

    printFirst(string, length);

    return 0;
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    printf("The predecessor of the char is : %c\n", ch - 1);
    printf("The successor of the char is : %c\n", ch + 1);

    return 0;
}
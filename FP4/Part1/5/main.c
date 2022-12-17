#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    char text1[26], text2[26];
    bool isEqual = true;

    printf("Enter the 1st text: \n");
    fgets(text1, sizeof(text1), stdin);

    printf("Enter the 2nd text: \n");
    fgets(text2, sizeof(text2), stdin);

    // if (strcmp(text1, text2) == 0)
    // {

    //     printf("The strings are equal.");
    // }

    for (int i = 0; i < 26; i++)
    {
        if (text1[i] == '\0' || text2[i] == '\0')
        {
            break;
        }
        if (text1[i] != text2[i])
        {
            isEqual = false;
            printf("The strings are not equal.");
            break;
        }
        isEqual = true;
    }

    if (isEqual)
    {
        printf("The strings are equal.");
    }

    return 0;
}
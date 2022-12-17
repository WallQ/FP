#include <stdio.h>

int equal(char *str1, char *str2)
{
    if (sizeof str1 != sizeof str2)
    {
        return 0;
    }
    else
    {
        int len = sizeof str1;

        for (size_t i = 0; i < len; i++)
        {
            if (str1[i] != str2[i])
            {
                return 0;
            }
        }

        return 1;
    }
}

int main(int argc, char *argv[])
{
    char string1[100], string2[100];

    printf("Enter the 1st string: ");
    scanf("%s", string1);
    printf("Enter the 2nd string: ");
    scanf("%s", string2);

    if (equal(string1, string2) == 1)
    {
        printf("The strings are equal.");
    }
    else if (equal(string1, string2) == 0)
    {
        printf("The strings are not equal.");
    }
    else
    {
        printf("Something went wrong.");
    }

    return 0;
}
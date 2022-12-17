#include <stdio.h>

int main(int argc, char *argv[])
{
    char message[26], ch;
    int shift;

    printf("Enter a message to encrypt: \n");
    fgets(message, sizeof(message), stdin);

    printf("Enter shift amount: \n");
    scanf("%d", &shift);

    for (size_t i = 0; message[i] != "\0"; ++i)
    {
        ch = message[i];
        if (ch >= "a" && ch <= "z")
        {
            ch = ch + shift;
            if (ch > "z")
            {
                ch = ch - "z" + "a" - 1;
            }
            message[i] = ch;
        }
        else if (ch >= "A" && ch <= "Z")
        {
            ch = ch + shift;
            if (ch > "Z")
            {
                ch = ch - "Z" + "A" - 1;
            }
            message[i] = ch;
        }
    }

    printf("Encrypted message: %s", message);

    return 0;
}
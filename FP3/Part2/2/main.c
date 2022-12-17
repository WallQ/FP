#include <stdio.h>

int main(int argc, char *argv[])
{
    int option;

    do
    {
        printf("1-Create\n2-Update\n3-Delete\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("The option chosen is 1 - Create\n");
                break;

            case 2:
                printf("The option chosen is 2 - Update\n");
                break;

            case 3:
                printf("The option chosen is 3 - Delete\n");
                break;

            default:
                break;
        }
    } while (option != 4);

    return 0;
}
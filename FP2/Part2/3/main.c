#include <stdio.h>

int main(int argc, char *argv[])
{
    int menuOp;

    printf("1. Create\n");
    printf("2. Update\n");
    printf("3. Delete\n");
    printf("4. Exit\n");

    printf("Enter your menu option: ");
    scanf("%d", &menuOp);

    switch (menuOp)
    {
        case 1:
            printf("You entered create option\n");
            break;
        case 2:
            printf("You entered update option\n");
            break;
        case 3:
            printf("You entered delete option\n");
            break;
        case 4:
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}
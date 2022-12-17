#include <stdio.h>

void displayMenu(void)
{
    printf("1. Sum\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Max number\n");
    printf("6. Min number\n");
    printf("7. Find potency\n");
    printf("0. Sair\n");
}

int readMenuOption(void)
{
    int menuOption;

    do
    {
        displayMenu();
        printf("Enter the option: ");
        scanf("%d", &menuOption);
    } while (menuOption != 0 && menuOption != 1 && menuOption != 2 && menuOption != 3 && menuOption != 4 && menuOption != 5 && menuOption != 6 && menuOption != 7);

    return menuOption;
}
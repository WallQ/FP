#include "menu.h"
#include "input.h"
#include <stdio.h>

void displayMenu()
{
    printf("1 - Create Student\n");
    printf("2 - Display Student\n");
    printf("3 - Display All Students\n");
    printf("4 - Update Student\n");
    printf("5 - Delete Student\n");
    printf("0 - Exit\n");
}

int menu()
{
    int option;

    displayMenu();
    option = getInt(0, 5, MESSAGE_GET_OPTION);

    return option;
}
#include "info.h"
#include <stdio.h>
#include <ctype.h>

char *readName(void)
{
    char name[50];

    printf("Enter the name: \n");
    fgets(name, sizeof(name), stdin);
}

int readCode(void)
{
    int code, result;

    do
    {
        printf("Enter your code: \n");
        result = scanf("%d", &code);
        fflush(stdin);
    } while (result != 1);

    return code;
}

void displayMenu(void)
{
    printf("E - Employee\n");
    printf("B - Boss\n");
    printf("A - Administrator\n");
}

char getRole(void)
{
    char role;

    do
    {
        displayMenu();
        printf("Enter your role: \n");
        scanf(" %c", &role);
    } while (role != 'E' && role != 'e' && role != 'B' && role != 'b' && role != 'A' && role != 'a');

    return role;
}

void readDaysWorked(int daysWorked[12])
{
    for (size_t i = 0; i < 12; i++)
    {
        do
        {
            printf("Enter how many days have you worked in the month %d: \n", i + 1);
            scanf("%d", &daysWorked[i]);
        } while (daysWorked[i] < 0 || daysWorked[i] > 31);
    }
}

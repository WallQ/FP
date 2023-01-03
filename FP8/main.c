#include "menu.h"
#include "student.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int option;
    Students students = {.index = 0};

    do
    {
        option = menu();

        switch (option)
        {
            case 1:
                insertStudents(&students);
                break;

            case 2:
                searchStudents(students);
                break;

            case 3:
                updateStudents(&students);
                break;

            case 4:
                deleteStudents(&students);
                break;

            case 5:
                viewStudents(students);
                break;

            case 0:
                printf("Exit\n");
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 0);

    return 0;
}
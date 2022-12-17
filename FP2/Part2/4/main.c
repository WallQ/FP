#include <stdio.h>

int main(int argc, char *argv[])
{
    float grade1, grade2;

    do
    {
        printf("Enter the 1st grade: ");
        scanf("%f", &grade1);
    } while (grade1 < 0 || grade1 > 20);

    do
    {
        printf("Enter the 2nd grade: ");
        scanf("%f", &grade2);
    } while (grade2 < 0 || grade2 > 20);

    if ((grade1 * 0.4) + (grade2 * 0.6) >= 9.5)
    {
        printf("The student is approved!");
    }
    else
    {
        printf("The student is not approved!");
    }

    return 0;
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    int age1, age2, age3;

    printf("Enter the age of the 1st student: ");
    scanf("%d", &age1);

    printf("Enter the age of the 2nd student: ");
    scanf("%d", &age2);

    printf("Enter the age of the 3rd student: ");
    scanf("%d", &age3);

    printf("The average age of students is: %f", (age1 + age2 + age3) / 3.0);

    return 0;
}
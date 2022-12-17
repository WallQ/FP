#include <stdio.h>

void sort(int *value1, int *value2, int *value3)
{
    int temp;

    if (*value1 > *value2)
    {
        temp = *value1;
        *value1 = *value2;
        *value2 = temp;
    }

    if (*value2 > *value3)
    {
        temp = *value2;
        *value2 = *value3;
        *value3 = temp;
    }

    if (*value1 > *value2)
    {
        temp = *value1;
        *value1 = *value2;
        *value2 = temp;
    }
}

int main(int argc, char *argv[])
{
    int value1, value2, value3;

    printf("Enter the 1st value\n");
    scanf("%d", &value1);
    printf("Enter the 2nd value\n");
    scanf("%d", &value2);
    printf("Enter the 2nd value\n");
    scanf("%d", &value3);

    sort(&value1, &value2, &value3);

    printf("The values in ascending order are %d, %d, %d\n", value1, value2, value3);

    return 0;
}
#include <stdio.h>

int main(int argc, char *argv[])
{
    float base, height;

    printf("Enter the base of the rectangle: ");
    scanf("%f", &base);

    printf("Enter the height of the rectangle: ");
    scanf("%f", &height);

    printf("The area of the rectangle is: %f\n", base * height);
    printf("The perimeter of the rectangle is: %f\n", (base + height) * 2);

    return 0;
}
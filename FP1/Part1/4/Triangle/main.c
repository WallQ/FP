#include <stdio.h>

int main(int argc, char *argv[])
{
    float base, height, side1, side2, side3;

    printf("Enter the base of the triangle: ");
    scanf("%f", &base);

    printf("Enter the height of the triangle: ");
    scanf("%f", &height);

    printf("Enter the sides of the triangle: ");
    scanf("%f %f %f", &side1, &side2, &side3);

    printf("The area of the triangle is: %f\n", (base * height) / 2.0);
    printf("The perimeter of the triangle is: %f\n", side1 + side2 + side3);

    return 0;
}
#include <stdio.h>
#define PI 3.141

int main(int argc, char *argv[])
{
    float diameter;

    printf("Enter the diameter of the circumference: ");
    scanf("%f", &diameter);

    printf("The area of the circumference is: %f\n", 2.0 * PI * (diameter / 2.0));
    printf("The perimeter of the circumference is: %f\n", PI * ((diameter / 2.0) * (diameter / 2.0)));

    return 0;
}
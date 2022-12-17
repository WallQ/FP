#include <stdio.h>

int main(int argc, char *argv[])
{
    float price1, price2, price3;

    printf("Enter the price of the 1st product: ");
    scanf("%f", &price1);

    printf("Enter the price of the 2nd product: ");
    scanf("%f", &price2);

    printf("Enter the price of the 3rd product: ");
    scanf("%f", &price3);

    printf("The total price of the three products is: %f", ((price1 + price2 + price3) - ((price1 + price2 + price3) * 0.1)));

    return 0;
}
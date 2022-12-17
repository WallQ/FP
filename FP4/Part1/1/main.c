#include <stdio.h>

#define MAX_PRODUCTS 10

int main(int argc, char *argv[])
{
    float prices[MAX_PRODUCTS], total;

    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        printf("Enter price for product %d: ", i + 1);
        scanf("%f", &prices[i]);
        total += prices[i];
    }

    printf("Total price: %.2f", total);

    return 0;
}
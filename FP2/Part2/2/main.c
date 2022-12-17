#include <stdio.h>

int main(int argc, char *argv[])
{
    float bankBalance, amount;

    printf("Enter your bank balance: ");
    scanf("%f", &bankBalance);

    printf("Enter the amount to credit/debit: ");
    scanf("%f", &amount);

    if (amount > 0)
    {
        bankBalance += amount;
        printf("Crediting %.2f to your account!\nNew balance: %.2f", amount, bankBalance);
    }
    else if (amount < 0)
    {
        if (bankBalance - amount < 0)
        {
            printf("Insufficient funds!");
        }
        else
        {
            bankBalance += amount;
            printf("Debiting %.2f from your account!\nNew balance: %.2f", amount, bankBalance);
        }
    }
    else
    {
        printf("No change in your account");
    }

    return 0;
}
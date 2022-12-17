#include <stdio.h>
#include <string.h>
#include "info/info.h"
#include "calcs/calcs.h"

int main(int argc, char *argv[])
{
    char name[50], role, continueOption;
    int code = 0, daysWorked[12];
    float salary = 0, food = 0, irs = 0, socialSecurity = 0, liquidSalary = 0, companyCost = 0;

    do
    {
        strcpy(name, readName());
        code = readCode();
        role = getRole();
        readDaysWorked(daysWorked);

        // switch (role)
        // {
        // case 'E':
        // case 'e':
        //     salary = calcSalary(daysWorked, role);
        //     food = calcFood(daysWorked, role);
        //     irs = calcIRS(salary, food);
        //     socialSecurity = calcSocialSecurity(salary, food, role);
        //     liquidSalary = calcLiquidSalary(salary, food, irs, socialSecurity);
        //     companyCost += calcCompanyCost(salary, food, socialSecurity);
        //     displayInfo(salary, food, irs, socialSecurity, liquidSalary);
        //     break;

        // case 'B':
        // case 'b':
        //     salary = calcSalary(daysWorked, role);
        //     food = calcFood(daysWorked, role);
        //     irs = calcIRS(salary, food);
        //     socialSecurity = calcSocialSecurity(salary, food, role);
        //     liquidSalary = calcLiquidSalary(salary, food, irs, socialSecurity);
        //     companyCost += calcCompanyCost(salary, food, socialSecurity);
        //     displayInfo(salary, food, irs, socialSecurity, liquidSalary);
        //     break;

        // case 'A':
        // case 'a':
        //     salary = calcSalary(daysWorked, role);
        //     food = calcFood(daysWorked, role);
        //     irs = calcIRS(salary, food);
        //     socialSecurity = calcSocialSecurity(salary, food, role);
        //     liquidSalary = calcLiquidSalary(salary, food, irs, socialSecurity);
        //     companyCost += calcCompanyCost(salary, food, socialSecurity);
        //     displayInfo(salary, food, irs, socialSecurity, liquidSalary);
        //     break;

        // default:
        //     break;
        // }

        printf("The total cost of the company is: %.2f\n", companyCost);

        do
        {
            printf("Do you want to continue? (Y/N): \n");
            scanf(" %c", &continueOption);
        } while (continueOption != 'Y' && continueOption != 'y' && continueOption != 'N' && continueOption != 'n');
    } while (continueOption != 'N' && continueOption != 'n');

    return 0;
}
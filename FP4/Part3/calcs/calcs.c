#include "calcs.h"
#include <stdio.h>

float calcSalary(int daysWorked, char role)
{
    float salary = 0;

    switch (role)
    {
        case 'E':
        case 'e':
            salary = daysWorked * SALARY_EMPLOYEE;
            salary += calcBonus(daysWorked, salary);
            break;

        case 'B':
        case 'b':
            salary = daysWorked * SALARY_EMPLOYER;
            salary += calcBonus(daysWorked, salary);
            break;

        case 'A':
        case 'a':
            salary = daysWorked * SALARY_ADMINISTRATOR;
            salary += calcBonus(daysWorked, salary);
            break;

        default:
            break;
    }

    return salary;
}

float calcBonus(int daysWorked, float salary)
{
    float bonus = 0;

    if (daysWorked >= 20)
        bonus = (salary * 0.05);
    else if (daysWorked >= 17)
        bonus = (salary * 0.02);

    return bonus;
}

float calcFood(int daysWorked, char role)
{
    float food = 0;

    switch (role)
    {
        case 'E':
        case 'e':
            food = daysWorked * FOOD_EMPLOYEE;
            break;

        case 'B':
        case 'b':
            food = daysWorked * FOOD_EMPLOYER;
            break;

        case 'A':
        case 'a':
            food = daysWorked * FOOD_ADMINISTRATOR;
            break;

        default:
            break;
    }

    return food;
}

float calcIRS(float salary, float food)
{
    float irs = 0, total = salary + food;

    if (salary < 1000)
        irs = total * IRS_LOW;
    else if (salary >= 1000 && salary < 2500)
        irs = total * IRS_MEDIUM;
    else if (salary >= 2500)
        irs = total * IRS_HIGH;

    return irs;
}

float calcSocialSecurity(float salary, float food, char role)
{
    float socialSecurity = 0, total = salary + food;

    switch (role)
    {
        case 'E':
        case 'e':
            socialSecurity = total * SOCIAL_SECURITY_EMPLOYEE;
            break;

        case 'B':
        case 'b':
            socialSecurity = total * SOCIAL_SECURITY_EMPLOYER;
            break;

        case 'A':
        case 'a':
            socialSecurity = total * SOCIAL_SECURITY_ADMINISTRATOR;
            break;

        default:
            break;
    }

    return socialSecurity;
}

float calcLiquidSalary(float salary, float food, float irs, float socialSecurity)
{
    float liquidSalary = 0;

    liquidSalary = (salary + food) - (irs + socialSecurity);

    return liquidSalary;
}

float calcCompanyCost(float salary, float food, float socialSecurity)
{
    float companyCost = 0, total = salary + food;

    companyCost = total + (total * SOCIAL_SECURITY_EMPLOYER);

    return companyCost;
}

void displayInfo(float salary, float food, float irs, float socialSecurity, float liquidSalary)
{
    printf("The net salary without taxes is: %.2f\n", salary);
    printf("The total food allowance is: %.2f\n", food);
    printf("The withholding tax is: %.2f\n", irs);
    printf("The social security is: %.2f\n", socialSecurity);
    printf("The net salary is: %.2f\n", liquidSalary);
}
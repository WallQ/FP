#include <stdio.h>

#define SALARY_EMPLOYEE 40
#define SALARY_EMPLOYER 60
#define SALARY_ADMINSTRATOR 80

#define FOOD_EMPLOYEE 5
#define FOOD_EMPLOYER 7.5
#define FOOD_ADMINSTRATOR 7.5

#define IRS_LOW 0.10
#define IRS_MEDIUM 0.20
#define IRS_HIGH 0.30

#define SOCIAL_SECURITY_EMPLOYEE 0.11
#define SOCIAL_SECURITY_EMPLOYER 0.2375
#define SOCIAL_SECURITY_ADMINSTRATOR 0.30

int main(int argc, char *argv[])
{
    char charge, option;
    int daysWorked;
    float salary, bonus, food, irs, socialSecurityEmployee, socialSecurityEmployer, socialSecurityAdminstrator, liquidSalary, companyTotal;

    do
    {
        do
        {
            printf("E-Employee\nB-Boss\nA-Administrator\n");
            printf("Enter your charge: ");
            scanf(" %c", &charge);
        } while (charge != 'E' && charge != 'e' && charge != 'B' && charge != 'b' && charge != 'A' && charge != 'a');

        printf("Enter how many days have you worked: ");
        scanf("%d", &daysWorked);

        switch (charge)
        {
            case 'E':
                salary = daysWorked * SALARY_EMPLOYEE;
                if (daysWorked >= 20)
                {
                    bonus = salary * 0.05;
                    salary += bonus;
                }
                else if (daysWorked >= 17)
                {
                    bonus = salary * 0.02;
                    salary += bonus;
                }
                food = FOOD_EMPLOYEE * daysWorked;
                if (salary < 1000)
                {
                    irs = salary * IRS_LOW;
                }
                else if (salary >= 1000 && salary < 2500)
                {
                    irs = salary * IRS_MEDIUM;
                }
                else if (salary >= 2500)
                {
                    irs = salary * IRS_HIGH;
                }
                socialSecurityEmployee = (salary + food) * SOCIAL_SECURITY_EMPLOYEE;
                liquidSalary = (salary + food) - (irs + socialSecurityEmployee);
                printf("The net salary of the employee without taxs is: %f\n", salary);
                printf("The total food allowance of the employee is: %f\n", food);
                printf("The withholding tax of the employee is: %f\n", irs);
                printf("The social security fee of the employee is: %f\n", socialSecurityEmployee);
                printf("The net salary of the employee: %f\n", liquidSalary);
                companyTotal = salary + food + ((salary + food) * SOCIAL_SECURITY_EMPLOYER);
                break;

            case 'B':
                salary = daysWorked * SALARY_EMPLOYER;
                if (daysWorked >= 20)
                {
                    bonus = salary * 0.05;
                    salary += bonus;
                }
                else if (daysWorked >= 17)
                {
                    bonus = salary * 0.02;
                    salary += bonus;
                }
                food = FOOD_EMPLOYER * daysWorked;
                if (salary < 1000)
                {
                    irs = salary * IRS_LOW;
                }
                else if (salary >= 1000 && salary < 2500)
                {
                    irs = salary * IRS_MEDIUM;
                }
                else if (salary >= 2500)
                {
                    irs = salary * IRS_HIGH;
                }
                socialSecurityEmployer = (salary + food) * SOCIAL_SECURITY_ADMINSTRATOR;
                liquidSalary = (salary + food) - (irs + socialSecurityEmployer);
                printf("The net salary of the employer without taxs is: %f\n", salary);
                printf("The total food allowance of the employer is: %f\n", food);
                printf("The withholding tax of the employer is: %f\n", irs);
                printf("The social security fee of the employer is: %f\n", socialSecurityEmployer);
                printf("The net salary of the employer: %f\n", liquidSalary);
                companyTotal = salary + food + socialSecurityEmployer;
                break;

            case 'A':
                salary = daysWorked * SALARY_ADMINSTRATOR;
                if (daysWorked >= 20)
                {
                    bonus = salary * 0.05;
                    salary += bonus;
                }
                else if (daysWorked >= 17)
                {
                    bonus = salary * 0.02;
                    salary += bonus;
                }
                food = FOOD_ADMINSTRATOR * daysWorked;
                if (salary < 1000)
                {
                    irs = salary * IRS_LOW;
                }
                else if (salary >= 1000 && salary < 2500)
                {
                    irs = salary * IRS_MEDIUM;
                }
                else if (salary >= 2500)
                {
                    irs = salary * IRS_HIGH;
                }
                socialSecurityAdminstrator = (salary + food) * SOCIAL_SECURITY_ADMINSTRATOR;
                liquidSalary = (salary + food) - (irs + socialSecurityAdminstrator);
                printf("The net salary of the adminstrator without taxs is: %f\n", salary);
                printf("The total food allowance of the adminstrator is: %f\n", food);
                printf("The withholding tax of the adminstrator is: %f\n", irs);
                printf("The social security fee of the adminstrator is: %f\n", socialSecurityAdminstrator);
                printf("The net salary of the adminstrator: %f\n", liquidSalary);
                companyTotal = salary + food + socialSecurityEmployer;
                break;

            default:
                break;
        }

        printf("The total cost of the company is: %f\n", companyTotal);

        do
        {
            printf("Do you want to continue? (Y/N): \n");
            scanf(" %c", &option);
        } while (option != 'Y' && option != 'y' && option != 'N' && option != 'n');
    } while (option != 'N' && option != 'n');

    return 0;
}
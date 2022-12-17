#include <stdio.h>

#define SALARY_EMPLOYEE 40
#define SALARY_EMPLOYER 60
#define SALARY_ADMINISTRATOR 80

#define FOOD_EMPLOYEE 5
#define FOOD_EMPLOYER 7.5
#define FOOD_ADMINISTRATOR 7.5

#define IRS_LOW 0.10
#define IRS_HIGH 0.20

#define SOCIAL_SECURITY_EMPLOYEE 0.11
#define SOCIAL_SECURITY_EMPLOYER 0.2375
#define SOCIAL_SECURITY_ADMINISTRATOR 0.30

int main(int argc, char *argv[])
{
    char charge;
    int daysWorked;
    double salary, food, irs = 0, socialSecurityEmployee, socialSecurityEmployer, socialSecurityAdministrator, liquidSalary;

    do
    {
        printf("E-Employee\nB-Boss\nA-Administrator\n");
        printf("Enter your charge: ");
        scanf(" %c", &charge);
    } while (charge != 'E' && charge != 'B' && charge != 'A');

    printf("Enter how many days have you worked: ");
    scanf("%d", &daysWorked);

    switch (charge)
    {
        case 'E':
            salary = daysWorked * SALARY_EMPLOYEE;
            food = FOOD_EMPLOYEE * daysWorked;
            if (salary < 1000)
            {
                irs = salary * IRS_LOW;
            }
            else if (salary >= 1000)
            {
                irs = salary * IRS_HIGH;
            }
            socialSecurityEmployee = (salary + food) * SOCIAL_SECURITY_EMPLOYEE;
            liquidSalary = (salary + food) - (irs + socialSecurityEmployee);
            printf("The net salary of the employee without tax's is: %f\n", salary);
            printf("The total food allowance of the employee is: %f\n", food);
            printf("The withholding tax of the employee is: %f\n", irs);
            printf("The social security fee of the employee is: %f\n", socialSecurityEmployee);
            printf("The net salary of the employee: %f\n", liquidSalary);
            break;

        case 'B':
            salary = daysWorked * SALARY_EMPLOYER;
            food = FOOD_EMPLOYER * daysWorked;
            if (salary < 1000)
            {
                irs = salary * IRS_LOW;
            }
            else if (salary >= 1000)
            {
                irs = salary * IRS_HIGH;
            }
            socialSecurityEmployer = (salary + food) * SOCIAL_SECURITY_EMPLOYER;
            liquidSalary = (salary + food) - (irs + socialSecurityEmployer);
            printf("The net salary of the employer without tax's is: %f\n", salary);
            printf("The total food allowance of the employer is: %f\n", food);
            printf("The withholding tax of the employer is: %f\n", irs);
            printf("The social security fee of the employer is: %f\n", socialSecurityEmployer);
            printf("The net salary of the employer: %f\n", liquidSalary);
            break;

        case 'A':
            salary = daysWorked * SALARY_ADMINISTRATOR;
            food = FOOD_ADMINISTRATOR * daysWorked;
            if (salary < 1000)
            {
                irs = salary * IRS_LOW;
            }
            else if (salary >= 1000)
            {
                irs = salary * IRS_HIGH;
            }
            socialSecurityAdministrator = (salary + food) * SOCIAL_SECURITY_ADMINISTRATOR;
            liquidSalary = (salary + food) - (irs + socialSecurityAdministrator);
            printf("The net salary of the administrator without tax's is: %f\n", salary);
            printf("The total food allowance of the administrator is: %f\n", food);
            printf("The withholding tax of the administrator is: %f\n", irs);
            printf("The social security fee of the administrator is: %f\n", socialSecurityAdministrator);
            printf("The net salary of the administrator: %f\n", liquidSalary);
            break;

        default:
            break;
    }

    return 0;
}
#include <stdio.h>

#define SALARY 40
#define FOOD 5
#define IRS 0.10
#define SOCIAL_SECURITY_EMPLOYEE 0.11
#define SOCIAL_SECURITY_EMPLOYER 0.2375

int main(int argc, char *argv[])
{
    int employeeCode, daysWorked;
    float salary, food, irs, socialSecurityEmployee, socialSecurityEmployer, liquidSalary;

    printf("Enter your employee code: ");
    scanf("%d", &employeeCode);

    printf("Enter how many days have you worked: ");
    scanf("%d", &daysWorked);

    salary = SALARY * daysWorked;
    printf("The net salary of the employee %d without taxs is: %f\n", employeeCode, salary);
    food = FOOD * daysWorked;
    printf("The total food allowance of the employee %d is: %f\n", employeeCode, food);
    irs = (salary + food) * IRS;
    printf("The withholding tax of the employee %d is: %f\n", employeeCode, irs);
    socialSecurityEmployee = (salary + food) * SOCIAL_SECURITY_EMPLOYEE;
    printf("The social security fee of the employee %d is: %f\n", employeeCode, socialSecurityEmployee);
    socialSecurityEmployer = (salary + food) * SOCIAL_SECURITY_EMPLOYER;
    printf("The social security fee of the employer %d is: %f\n", employeeCode, socialSecurityEmployer);
    liquidSalary = (salary + food) - (irs + socialSecurityEmployee);
    printf("The net salary of the employee %d: %f\n", employeeCode, liquidSalary);

    return 0;
}
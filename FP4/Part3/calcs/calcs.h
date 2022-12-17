#ifndef CALCS_H
#define CALCS_H

#define SALARY_EMPLOYEE 40
#define SALARY_EMPLOYER 60
#define SALARY_ADMINISTRATOR 80

#define FOOD_EMPLOYEE 5
#define FOOD_EMPLOYER 7.5
#define FOOD_ADMINISTRATOR 7.5

#define IRS_LOW 0.10
#define IRS_MEDIUM 0.20
#define IRS_HIGH 0.30

#define SOCIAL_SECURITY_EMPLOYEE 0.11
#define SOCIAL_SECURITY_EMPLOYER 0.2375
#define SOCIAL_SECURITY_ADMINISTRATOR 0.30

float calcSalary(int daysWorked, char role);
float calcBonus(int daysWorked, float salary);
float calcFood(int daysWorked, char role);
float calcIRS(float salary, float food);
float calcSocialSecurity(float salary, float food, char role);
float calcLiquidSalary(float salary, float food, float irs, float socialSecurity);
float calcCompanyCost(float salary, float food, float socialSecurity);
void displayInfo(float salary, float food, float irs, float socialSecurity, float liquidSalary);

#endif
#include <math.h>
#include "intLib.h"

float sum(float num1, float num2)
{
    return num1 + num2;
}

float subtract(float num1, float num2)
{
    return num1 - num2;
}

float multiply(float num1, float num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    return num1 / num2;
}

float maxNum(float num1, float num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

float minNum(float num1, float num2)
{
    if (num1 < num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

float findPotency(float num1, float num2)
{
    if (num2 = 0)
    {
        return 1;
    }
    else if (num2 > 0)
    {
        return num1 * findPotency(num1, num2 - 1);
    }
    else if (num2 < 0)
    {
        return 1 / findPotency(num1, -num2);
    }
}

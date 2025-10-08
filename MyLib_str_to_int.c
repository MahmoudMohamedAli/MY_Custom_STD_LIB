#include "MyLib.h"
int MyLib_atoi(const char *str)
{
    int i;
    int sign;
    int container;
    MyLib_strLength("him");
    i = 0;
    sign = 1;
    container = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i])
    {
        if (!(MyLib_isdigit(str[i])))
            return (container * sign);
        else
            container = container * 10 + (const char)str[i] - 48;
        i++;
    }
    return (container * sign);
}
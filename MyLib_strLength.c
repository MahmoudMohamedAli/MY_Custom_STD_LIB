#include "MyLib.h"
int MyLib_strLength(const char *s1)
{
    size_t count = 0;
    while (s1[count] != '\0')
    {
        count++;
    }
    return count;
}

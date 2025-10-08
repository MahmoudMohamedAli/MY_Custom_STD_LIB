#include "MyLib.h"

// Description
// 0 equal
//-1 equal in length but not equal in character
// 1 str1 is bigger
// 2 str2 is bigger
int MyLib_memcompare(const char *s1, const char *s2)
{
    int i = 0;
    if (MyLib_strLength(s1) > MyLib_strLength(s2))
        return 1;
    if (MyLib_strLength(s1) < MyLib_strLength(s2))
        return 2;

    while (s1[i] == s2[i])
    {
        i++;
        if (s1[i] == '\0')
            return 0;
    }
    return -1;
}

int MyLib_MemCompare_Efficient(const char *s1, const char *s2)
{
    while (*s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;
    }
    return (unsigned char *)s1 - (unsigned char *)s2 > 0 ? 1 : (unsigned char *)s1 - (unsigned char *)s2 < 0 ? -1
                                                                                                             : 0;
}
int main()
{
    printf("hello %d \n", MyLib_memcompare("himak!!", "himan!!"));
    printf("hello %d \n", MyLib_MemCompare_Efficient("himak!!", "himan!!"));
    return 0;
}
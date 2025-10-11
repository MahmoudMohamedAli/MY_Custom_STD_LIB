#ifndef MY_LIB_H
#define MY_LIB_H
#include <stdio.h>
int MyLib_atoi(const char *str);
int MyLib_isdigit(int c);
int MyLib_strLength(const char *s1);
void My_Lib_memcpy(void *dest, const void *src, size_t n);
void My_Lib_memcpy_Efficient(void *dest, const void *src, size_t n);
#endif
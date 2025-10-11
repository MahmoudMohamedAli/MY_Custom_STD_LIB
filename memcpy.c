#include <stdio.h>
#define WORD_SIZE sizeof(unsigned long)
#define WORD_MASK (WORD_SIZE - 1)
#define WORD_ALIGN(p) (((unsigned long)(p) & WORD_MASK) == 0)
typedef unsigned long word_t;
void My_Lib_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
}

// if you have very large data to copy, use this function

void My_Lib_memcpy_Efficient(void *dest, const void *src, size_t n)
{
    // align
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    while (n > 0 && (((unsigned long)d & WORD_MASK) != 0))
    {
        *d++ = *s++;
        n--;
    }
    // copy word by word
    word_t *dw = (word_t *)d;
    const word_t *sw = (const word_t *)s;
    while (n >= WORD_SIZE)
    {
        *dw++ = *sw++;
        n -= WORD_SIZE;
    }
    // copy remaining bytes
    d = (unsigned char *)dw;
    s = (const unsigned char *)sw;
    while (n > 0)
    {
        *d++ = *s++;
        n--;
    }
}
#include <stddef.h>

#include <string.h>

int memcmp(const void *str1, const void *str2, size_t n)
{
    const unsigned char *ptr1 = str1, *ptr2 = str2;
    while (n--)
        if (*ptr1++ != *ptr2++)
            return *(ptr1 - 1) - *(ptr2 - 1);
    return 0;
 }

void *memcpy(void *dest, const void *src, size_t n)
{
    const unsigned char *srcp = src;
    unsigned char *destp = dest;
    while ((*destp++ = *srcp++) && n--);
    return dest;
}

// On peut probablement faire mieux avec __np_anyptrlt, TODO ?
void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char temp[n];
    memcpy(temp, src, n);
    memcpy(dest, temp, n);
    return dest;
}

void *memset(void *str, int c, size_t n)
{
    unsigned char* ptr=str;
    while(n--)
        *ptr++ = (unsigned char) c;
    return str;
}

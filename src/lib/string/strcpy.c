#include <stddef.h>

char *strcpy(char *dest, const char *src)
{
    char *res = dest;
    while ((*dest++ = *src++));
    return res;
}

char *strncpy(char *dest, const char *src, size_t n)
{
    char *res = dest;
    while ((*dest++ = *src++) && n--);
    while (n--)
        *dest++ = 0;
    return res;
}

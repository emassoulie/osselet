#include <stddef.h>
#include <stdio.h>

char *strcat(char *dest, const char *src)
{
    char *res = dest;
    while (*dest) {
        dest++;
    };
    while ((*dest++ = *src++))
        putchar('a');
    return res;
}

char* strncat(char* dest, const char* src, size_t n)
{
    char *res = dest;
    while (*dest) {
        dest++;
    }
    while ((*dest++ = *src++) && n--);
    return res;
}


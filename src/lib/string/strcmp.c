#include <stddef.h>

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1++ == *str2++));
    return *(str1 - 1) - *(str2 - 1);
 }

int strncmp(const char* str1, const char* str2, size_t n)
{
    while (n--)
        if (*str1++ != *str2++)
            return *(str1 - 1) - *(str2 - 1);
    return 0;
}

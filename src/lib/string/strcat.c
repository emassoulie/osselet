#include <stddef.h>

// sûrement source d'erreurs, à réecrire avec un malloc ?

char *strcat(char *dest, const char *src)
{
    char *res = dest;
    while ((*dest++ = *src++));
    return res;
}

char* strncat(char* dest, const char* src, size_t n)
{
    char *res = dest;
    while ((*dest++ = *src++) && n--);
    return res;
}


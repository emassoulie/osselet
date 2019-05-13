#include <string.h>
#include <stdio.h>

// surement source d'erreurs, à réecrire impérativement avec un malloc !

char *strcat(char *dest, const char *src) {
    char *ptr = dest + strlen(dest);
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

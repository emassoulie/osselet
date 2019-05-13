#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>

size_t strlen(const char *str);
int strcmp(const char *str1, const char *str2);
char *strrev(char *str);
char *strcat(char *dest, const char *src);

#endif

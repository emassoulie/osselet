#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>

size_t strlen(const char *str);
char *strrev(char *str);

int memcmp(const void *str1, const void *str2, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *str, int c, size_t n);

int strcmp(const char *str1, const char *str2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);

int strncmp(const char *str1, const char *str2, size_t n);
char *strncpy(char *dest, const char *src, size_t n);
char *strncat(char *dest, const char *src, size_t n);

#endif

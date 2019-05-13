#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include <stdio.h>

int puts(const char *str) {
    return printf("%s\n", str);
}

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <tty.h>

int printf(const char *format,...) { 
    va_list params; 
    va_start(params, format); 
    
    int written = 0;
    
    int i;
    char *s;

    while (*format != '\0') {
        if (format[0] != '%' || (strlen(format) > 0 && format[1] == '%')) {
            if (format[0] == '%')
                format++;
            putchar(*format);
            format++;
            written++;
        } else {
            format++;
            switch(*format) {
                case 'c': i = va_arg(params, int);
                          putchar(i);
                          written++;
                          break;
                case 's': s = va_arg(params, char*);
                          written += printf(s);
                          break;
                case 'd': i = va_arg(params, int);
                          if (i < 0) {
                              i = -i;
                              putchar('-');
                          }
                          char result[50]; // Longueur max arbitraire
                          char* ptr = result;
                          do {
                              *ptr = "0123456789"[i%10];
                              ptr++;
                              i /= 10;
                              written++;
                          } while (i != 0);
                          *ptr = '\0';
                          printf(strrev(result));
                }
            format++;
        }
    }
    va_end(params);
    return written;
} 

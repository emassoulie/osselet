#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include "../stdio.h"
#include "../string.h"
#include "../tty.h"

int printf(char *format,...) { 
    va_list params; 
    va_start(params, format); 
    
    int written = 0;

    int i;

    while (*format != '\0') {
        if (format[0] != '%' || (strlen(format) > 0 && format[1] == '%')) {
            if (format[0] == '%') {
                format++;
            }
            terminal_putchar(*format);
            format++;
            written++;
        } else {
            format++;
            switch(*format) {
                case 'c': i = va_arg(params, int);
                          terminal_putchar(i);
                          break;
                case 'd': i = va_arg(params, int);
                          if (i < 0) {
                              i = -i;
                              terminal_putchar('-');
                          }
                          char result[50];
                          char* ptr = result;
                          do {
                              *ptr++ = "0123456789"[i%10];
                              i /= 10;
                              written++;
                          } while (i != 0);
                          *ptr-- = '\0';
                          printf(result);
            format++;
            }
        }
    }
    va_end(params);
    return written;
} 

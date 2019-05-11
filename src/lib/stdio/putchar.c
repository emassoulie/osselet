#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include "../headers/stdio.h"
#include "../headers/tty.h"

int putchar(char c) { 
    terminal_putchar(c);
    return (int) c;
} 

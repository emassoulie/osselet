#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include "../stdio.h"
#include "../tty.h"

int putchar(char c) { 
    terminal_putchar(c);
    return (int) c;
} 

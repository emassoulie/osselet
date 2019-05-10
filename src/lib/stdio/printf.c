#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include "lib/stdio.h"
#include "lib/tty.h"

void printf(char *format,...) 
{ 
    char *traverse;
    unsigned int i;
    char *s;
 
    va_list arg; 
    va_start(arg, format); 
    for (traverse = format; *traverse != '\0'; traverse++) 
    { 
        while(*traverse != '%' & *traverse != '\0') 
        { 
            terminal_putchar(*traverse);
            traverse++; 
        } 

        if (traverse == '%') {
            traverse++; 
            switch(*traverse) { 
                case 'c' : i = va_arg(arg, int);     //Fetch char argument
                    terminal_putchar(i);
                    break; 
                            
                case 'd' : i = va_arg(arg, int);         //Integer
                    if(i < 0) { 
                        i = -i;
                        terminal_putchar('-'); 
                    } 
                    printf(convert(i, 10));
                    break; 
                            
                case 'o': i = va_arg(arg, unsigned int); //Octal
                    printf(convert(i,8));
                    break ;
                            
                case 's': s = va_arg(arg, char*);       //String
                    printf(s); 
                    break; 
                            
                case 'x': i = va_arg(arg, unsigned int); //Hexadecimal
                    printf(convert(i,16));
                    break; 
            }
        }   
    } 
    
    va_end(arg); 
} 

char *convert(unsigned int num, int base)
{
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;

    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }while(num != 0);

    return(ptr);
}

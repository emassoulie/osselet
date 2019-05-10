#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include "printf.h"
#include "string.h"
#include "tty.h"

void my_printf(char *format,...) 
{ 
    char *traverse;
    unsigned int i;
    char *s;
 
    //Module 1: Initializing Mymy_printf's arguments 
    va_list arg; 
    va_start(arg, format); 
    for (traverse = format; *traverse != '\0'; traverse++) 
    { 
        while(*traverse != '%') 
        { 
            terminal_putchar(*traverse);
            traverse++; 
        } 
        //Module 2: Fetching and executing arguments
        traverse++; 
        switch(*traverse) { 
            case 'c' : i = va_arg(arg, int);     //Fetch char argument
                terminal_putchar(i);
                break; 
                        
            case 'd' : i = va_arg(arg, int);         //Fetch Decimal/Integer argument
                if(i < 0) { 
                    i = -i;
                    terminal_putchar('-'); 
                } 
                my_printf(convert(i, 10));
                break; 
                        
            case 'o': i = va_arg(arg, unsigned int); //Fetch Octal representation
                my_printf(convert(i,8));
                break ;
                        
            case 's': s = va_arg(arg, char*);       //Fetch string
                my_printf(s); 
                break; 
                        
            case 'x': i = va_arg(arg, unsigned int); //Fetch Hexadecimal representation
                my_printf(convert(i,16));
                break; 
        }   
    } 
    
    //Module 3: Closing argument list to necessary clean-up
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

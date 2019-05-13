#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>
#include <tty.h>
 
void kernel_main(void) {

    terminal_initialize();

    printf("Hello, world!\n");
    printf("%d\n", 12345);
    printf("%c\n", 't');
    printf("%s\n", "test");
    char* str = strcat("COU", "cou");
    printf(str);
}

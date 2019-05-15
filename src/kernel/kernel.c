#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>
#include <tty.h>
 
void kernel_main(void) {

    terminal_initialize();
    
    char version[3] = "0.1";
    printf("OSselet, version %s\n", version);
    char str = strcat("cou", "COU");
    printf("%d\n", 123456789);
    printf("%d\n", 1234567);
    printf("\n\nFin.");
}

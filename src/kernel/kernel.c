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
}

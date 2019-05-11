#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "../lib/headers/string.h"
#include "../lib/headers/stdio.h"
#include "../lib/headers/tty.h"

 
void kernel_main(void) 
{
    /* Initialize terminal interface */
    terminal_initialize();
 
    /* Newline support is left as an exercise. */
    for (int i = 0; i < 10; i++) {
        printf("Hello, kernel World! %d\n", i);
    }
    printf("Hello, kernel ! test %d\n", 103209410);
    printf("Hello, kernel ! test %d\n", 101);
}

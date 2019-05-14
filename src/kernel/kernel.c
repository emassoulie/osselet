#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>
#include <tty.h>
 
void kernel_main(void) {

    terminal_initialize();

    printf("%d\n", memcmp("cous", "cous", 3));
    printf("%d\n", memcmp("cous", "coxs", 2));
    printf("%d\n", memcmp("cous", "coxs", 3));
    printf("%d\n", memcmp("cous", "coxs", 4));
    printf("%d\n", memcmp("cou", "cox", 2));
}

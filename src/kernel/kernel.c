#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>
#include <tty.h>

#include "../usr/shell/shell.h"

void kernel_main(void) {

    terminal_initialize();
    
    char version[3] = "0.1";
    printf("OSselet, version %s\n", version);
    shell_eval("cat fichier_1 fichier_2 fichier_3");
    shell_eval("echo coucou");
    printf("Fin.");
}

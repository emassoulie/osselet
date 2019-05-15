#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>
#include <tty.h>

#include "../usr/shell/shell.h"



void kernel_initialize()
{
    idt_init();
    kb_init();
}

void kernel_main(void)
{
    kernel_initialize();
	terminal_initialize();
    
    char version[3] = "0.1";
    printf("OSselet, version %s\n", version);
    shell_eval("cat fichier1 fichier2 fichier3");
    shell_eval("echo \"couc>&ou toi\"");
    shell_eval("pwd");
    printf("Fin.");

    while(1); /*idem*/
}

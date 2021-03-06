#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>
#include <tty.h>

#include <filesystem.h>

#include "../usr/shell/shell.h"



void kernel_initialize()
{
    terminal_initialize();
    ofs_init();
    idt_init();
}

void kernel_main(void)
{
    kernel_initialize();
    
    char version[3] = "0.1";
    printf("OSselet, version %s\n\n", version);
    
    shell_eval("echo test");

    // shell_eval("touch test");

    // shell_eval("ls");

    // shell_eval("rm fichier 3");

    kb_read();

    printf("Fin.");
}

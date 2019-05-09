#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "string.h"
#include "tty.h"

 
void kernel_main(void) 
{
    /* Initialize terminal interface */
    terminal_initialize();
 
    /* Newline support is left as an exercise. */
    terminal_writestring("Hello, kernel World!\n");
    terminal_writestring("Hello, kernel World! tes tes tes ètes tes tsip ma sfhjmghjasm fjg mkasgjf mjg mkasgfm gâusg kmg acg mkj iuasg kjmqxc bmknhua zh");
        terminal_scrolldown(1);
}

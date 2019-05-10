/*
 *  kernel.c
 */

#include "kernel.h"
#include "screen.h"

void kernel_main(void) {
    clearScreen();
    printLine("premier tests de micro-noyau", 0, 0);
    printLine("ligne deux (trois)", 2, 0);
    for (int i = 0; i < 50; i++) {
        printLine("coucou", i, 0);
        sleep(1);
    }
    for (int i = 0; i < 50; i++) {
        scrollDown();
        sleep(1);
    }
    return;
}

void sleep(int seconds) {
     for (int s = 0; s < seconds; s++) {
        for (int i = 0; i < 1e8; i++) {
            asm("nop");
        }
    }
 }

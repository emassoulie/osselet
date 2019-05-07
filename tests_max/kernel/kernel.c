/*
 *  kernel.c
 */

#include "kernel.h"
#include "screen.h"

void kernel_main() {
    clearScreen();
    printLine("premier tests de micro-noyau", 0, 0);
    printLine("ligne deux (trois)", 2, 0);
    for (int i = 0; i < 10; i++) {
        printLine("coucou", 0, 0);
        sleep(1);
        scrollDown();
        sleep(1);
    }
    return;
}

void sleep(int seconds) {
     for (int s = 0; s < seconds; s++) {
        for (int i = 0; i < 1.3e9; i++) {
            asm("nop");
        }
    }
 }

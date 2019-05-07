/*
 * screen.c
 */

#include "screen.h"

char *vidptr = (char*)0xb8000;
int LINEWIDTH = 80;
int VIDPTR_SIZE = 2*80*25;

void clearScreen() {
    int i = 0;
    while (i < VIDPTR_SIZE) {
        vidptr[i++] = ' ';
        vidptr[i++] = 0x08;  // Couleur
    }
}

void printLine(char* string, int line, int column) {
    int i = (LINEWIDTH * line + column) * 2;
    int j = 0;
    while (string[j] != '\0') {
        if (string[j] == '\n') {
            i += LINEWIDTH;
            i %= LINEWIDTH;
        };
        /* the character's ascii */
        vidptr[i++] = string[j++];
        /* attribute-byte: give character black bg and light grey fg */
        vidptr[i++] = 0x02;
    }
}

void scrollDown() {
    int i = 0;
    while (i < VIDPTR_SIZE) {
        if (i + 2*LINEWIDTH < VIDPTR_SIZE) {
            vidptr[i] = vidptr[i + 2*LINEWIDTH];
            i++;
            vidptr[i] = vidptr[i + 2*LINEWIDTH];
            i++;
        } else {
            vidptr[i++] = ' ';
            vidptr[i++] = 0x08;  // Couleur
        }
    } 
}

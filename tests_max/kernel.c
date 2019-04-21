/*
*  kernel.c
*/

void printLine(char* string, int line, int column);
void clearScreen();

char *vidptr = (char*)0xb8000;

void kmain(void) {
    clearScreen();
    printLine("premier tests de micro-noyau", 0, 0);
    printLine("ligne deux (trois)", 2, 0);
    return;
}

void clearScreen() {
    int i = 0;
    while (i < 160 * 25 * 2) {
        vidptr[i++] = ' ';
        vidptr[i++] = 0x08;  // Couleur
    }
}

void printLine(char* string, int line, int column) {
    int start = 160 * line + column;
    int i = 0;
    while (string[i] != '\0') {
        /* the character's ascii */
        vidptr[start + 2*i] = string[i];
        /* attribute-byte: give character black bg and light grey fg */
        vidptr[start + 2*i+1] = 0x07;
        i++;
    }
}

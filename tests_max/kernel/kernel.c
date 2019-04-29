/*
*  kernel.c
*/

void printLine(char* string, int line, int column);
void clearScreen();
void scrollDown();
void sleep(int seconds);

char *vidptr = (char*)0xb8000;
int LINEWIDTH = 80;
int VIDPTR_SIZE = 2*80*25;

void kernel_main(void) {
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

void sleep(int seconds) {
     for (int s = 0; s < seconds; s++) {
        for (int i = 0; i < 1.3e9; i++) {
            asm("nop");
        }
    }
 }

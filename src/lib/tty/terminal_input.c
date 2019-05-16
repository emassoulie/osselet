#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <stdio.h>
#include <tty.h>

#include <../../usr/shell/shell.h>

/*
* Inspiré de Arjun Sreedharan
*/

#include "keyboard_map.h"


#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

#define ESC_KEY_CODE 0x1
#define ENTER_KEY_CODE 0x1C
#define BACKSPACE_KEY_CODE 0xE
#define CAPS_KEY_CODE 0x2A


extern unsigned char keyboard_map[128];
extern void keyboard_handler(void);
extern char read_port(unsigned short port);
extern void write_port(unsigned short port, unsigned char data);
extern void load_idt(unsigned long *idt_ptr);

/* current cursor location */
unsigned int current_loc = 0;

struct IDT_entry {
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
};

struct IDT_entry IDT[IDT_SIZE];


void idt_init(void)
{
    unsigned long keyboard_address;
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    /* populate IDT entry of keyboard's interrupt */
    keyboard_address = (unsigned long)keyboard_handler;
    IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
    IDT[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
    IDT[0x21].zero = 0;
    IDT[0x21].type_attr = INTERRUPT_GATE;
    IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

    /*     Ports
    *	 PIC1	PIC2
    *Command 0x20	0xA0
    *Data	 0x21	0xA1
    */

    /* ICW1 - begin initialization */
    write_port(0x20 , 0x11);
    write_port(0xA0 , 0x11);

    /* ICW2 - remap offset address of IDT */
    /*
    * In x86 protected mode, we have to remap the PICs beyond 0x20 because
    * Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
    */
    write_port(0x21 , 0x20);
    write_port(0xA1 , 0x28);

    /* ICW3 - setup cascading */
    write_port(0x21 , 0x00);
    write_port(0xA1 , 0x00);

    /* ICW4 - environment info */
    write_port(0x21 , 0x01);
    write_port(0xA1 , 0x01);
    /* Initialization finished */

    /* mask interrupts */
    write_port(0x21 , 0xff);
    write_port(0xA1 , 0xff);

    /* fill the IDT descriptor */
    idt_address = (unsigned long)IDT ;
    idt_ptr[0] = (sizeof (struct IDT_entry) * IDT_SIZE) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16 ;

    load_idt(idt_ptr);
}

bool input_over = true;
char input_line[256];
char *input_ptr = input_line;

void kb_open()
{
    input_over = false;
    write_port(0x21 , 0xFD);
}

void kb_close()
{
    input_over = true;
    /* mask interrupts */
    write_port(0x21 , 0xff);
    write_port(0xA1 , 0xff);
    write_port(KEYBOARD_STATUS_PORT, 0x00);
    printf("\n");
    read_line(input_line);
}

char *kb_read()
{
    printf("\n> ");
    for (int i = 0; i < 256; i++)
        input_line[i] = '\0';
    input_ptr = input_line;
    kb_open();
    int i = 0;
    while (!input_over);
    printf("\nkb_read() finished\n");
    return input_line;
}

void keyboard_handler_main()
{

    unsigned char status;
    char keycode;
    char chr;

    /* write EOI */
    write_port(0x20, 0x20);
    
    status = read_port(KEYBOARD_STATUS_PORT);
    /* Lowest bit of status will be set if buffer is not empty */
    if  (status & 0x01) {
        keycode = read_port(KEYBOARD_DATA_PORT);
        if (keycode < 0) {
        }
        else if (keycode == BACKSPACE_KEY_CODE) {
            terminal_backspace();
            if (input_ptr > input_line)
                *--input_ptr = '\0';
        }
        else if (keycode == ENTER_KEY_CODE) {
            return kb_close();
        }
        else {
            chr = keyboard_map_lower[(unsigned char) keycode];
            terminal_putchar(chr);
            *input_ptr++ = chr;
        }
    }
    return;
}

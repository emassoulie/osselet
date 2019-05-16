#ifndef TTY_H_
#define TTY_H_


#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

#define ENTER_KEY_CODE 0x1C

void terminal_initialize(void);
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
uint16_t terminal_getentryat(size_t x, size_t y);
void terminal_scrolldown(int n);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_writenewline(const char* data);
void terminal_move_left();
void terminal_move_right();
void terminal_backspace();

void kb_open();
void kb_close();
char *kb_read();

#endif

#ifndef TTY_H_
#define TTY_H_

void terminal_initialize(void);
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
uint16_t terminal_getentryat(size_t x, size_t y);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_writenewline(const char* data);
void terminal_scrolldown(int n);
#endif

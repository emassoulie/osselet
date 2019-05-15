#ifndef _UNISTD_H
#define _UNISTD_H

#include <stdint.h>

int brk(void *addr);
void *sbrk(intptr_t increment); 

#endif

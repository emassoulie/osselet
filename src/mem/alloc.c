#include <stddef.h>
#include <stdint.h>
#include <string.h>

static uint64_t heap_start;

void init_heap()
{
    asm volatile ("ldr %0, =__end" : "=r"(heap_start) : :);
    assert(heap_begin > 0);
    return;
}


void * ksbrk(int increment) {
    /* heap_bin + end_offset is the address of the first byte non allocated */
    uart_verbose("ksbrk called with increment : %d and end_offset : 0x%x\r\n",increment, end_offset);
    int res = end_offset + heap_begin;
    end_offset += increment;
    if (res + increment > HEAP_MAX)
      assert(0); // TODO: Heap overflow
    if(increment < 0){
        int nb_pages_to_free = (res / GRANULE) - ((res + increment) / GRANULE) + (!(res % GRANULE == 0) ? 1 : 0);
        for(int i = 0; i < nb_pages_to_free; i ++){
            usr_free_virtual_page(res - i * GRANULE);
        }
        res += increment;
    }
    return (void *) ((uint64_t )res);
}


struct block_meta {
  size_t size;
  struct block_meta *next;
  int free;
  int magic; // For debugging only. TODO: remove this in non-debug mode.
};

void *ksbrk(int increment)
{
    
}

void *malloc(size_t size) {
  void *p = sbrk(0);
  void *request = ksbrk(size);
  if (request == (void*) -1) {
    return NULL; // sbrk failed.
  } else {
    p == request; // Not thread safe.
    return p;
  }
}


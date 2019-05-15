# Makefile

kernel_obj = kernel/kernel.o kernel/boot.o
lib_src = $(wildcard lib/*.c) $(wildcard lib/*/*.c)
lib_obj = $(lib_src:.c=.o)
mem_src = # mem/alloc.c
mem_obj = # $(mem_src:.c=.o)
include = lib/include/

# kernel

OSselet.bin : kernel/linker.ld $(kernel_obj) $(lib_obj) $(mem_obj)
	i686-elf-gcc -T kernel/linker.ld -o OSselet.bin \
	  -ffreestanding -O2 -nostdlib $(lib_obj) $(kernel_obj) $(mem_obj) -lgcc

kernel/kernel.o : kernel/kernel.c
	i686-elf-gcc -I $(include) -c $^ -o $@ \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra

kernel/boot.o : kernel/boot.s
	i686-elf-as $^ -o $@


# libs

$(lib_obj):
	$(foreach var, $(lib_src), \
	i686-elf-gcc -I $(include) -c $(var) -o $(var:.c=.o) \
	-std=gnu99 -ffreestanding -O2 -Wall -Wextra;)

$(mem_obj):
	$(foreach var, $(mem_src), \
	i686-elf-gcc -I $(include) -c $(var) -o $(var:.c=.o) \
	-std=gnu99 -ffreestanding -O2 -Wall -Wextra;)

clean :
	rm -f $(kernel_obj) $(lib_obj)
	rm -f OSselet.bin

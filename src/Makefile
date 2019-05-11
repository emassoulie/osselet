# Makefile

kernel_obj = kernel/kernel.o kernel/boot.o
lib_src = $(wildcard lib/*.c) $(wildcard lib/*/*.c)
lib_obj = $(lib_src:.c=.o)

# kernel

myos.bin : kernel/linker.ld $(kernel_obj) $(lib_obj)
	i686-elf-gcc -T kernel/linker.ld -o myos.bin \
	  -ffreestanding -O2 -nostdlib $(lib_obj) $(kernel_obj) -lgcc

kernel/kernel.o : kernel/kernel.c
	i686-elf-gcc -c $^ -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

kernel/boot.o : kernel/boot.s
	i686-elf-as $^ -o $@


# libs

$(lib_obj):
	$(foreach var, $(lib_src), \
	i686-elf-gcc -c $(var) -o $(var:.c=.o) \
	-std=gnu99 -ffreestanding -O2 -Wall -Wextra;)

clean :
	rm -f *.o
	rm -f myos.bin
	rm -f lib/*.o

# Makefile

kernel_obj = kernel/kernel.o kernel/boot.o

lib_src = $(wildcard lib/*.c) $(wildcard lib/*/*.c)
lib_obj = $(lib_src:.c=.o)

mem_src = # mem/alloc.c
mem_obj = # $(mem_src:.c=.o)

include = lib/include/
apps = usr/

usr_src = usr/shell/shell.c
usr_obj = $(usr_src:.c=.o)

# kernel

OSselet.bin : kernel/linker.ld $(kernel_obj) $(lib_obj) $(usr_obj)
	i686-elf-gcc -T kernel/linker.ld -o OSselet.bin \
	  -ffreestanding -O2 -nostdlib \
	  $(lib_obj) $(kernel_obj) $(usr_obj) -lgcc

kernel/kernel.o : kernel/kernel.c
	i686-elf-gcc -I $(include) -I $(apps) -c $^ -o $@ \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra

kernel/boot.o : kernel/boot.s
	i686-elf-as $^ -o $@


# libs

$(lib_obj):
	$(foreach var, $(lib_src), \
		i686-elf-gcc -I $(include) -I $(apps) \
		  -c $(var) -o $(var:.c=.o) \
		  -std=gnu99 -ffreestanding -O2 -Wall -Wextra ;)

$(mem_obj):
	$(foreach var, $(mem_src), \
		i686-elf-gcc -I $(include) -I $(apps) \
		  -c $(var) -o $(var:.c=.o) \
		  -std=gnu99 -ffreestanding -O2 -Wall -Wextra ;)


# usr

$(usr_obj):
	$(foreach var, $(usr_src), \
		i686-elf-gcc -I $(include) -I $(apps) \
		  -c $(var) -o $(var:.c=.o) \
		  -std=gnu99 -ffreestanding -O2 -Wall -Wextra ;)

clean :
	rm -f $(kernel_obj) $(lib_obj) $(usr_obj)
	rm -f OSselet.bin

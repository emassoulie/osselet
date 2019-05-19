# Makefile

kernel_obj = kernel/kernel.o kernel/boot.o

lib_src = $(wildcard lib/*.c) $(wildcard lib/*/*.c)
lib_obj = $(lib_src:.c=.o)

mem_src = mem/filesystem.c
mem_obj = $(mem_src:.c=.o)

include = lib/include/
apps = usr/
mem = mem/

usr_src = usr/shell/shell.c
usr_obj = $(usr_src:.c=.o)

# kernel

OSselet.bin : kernel/linker.ld $(kernel_obj) $(lib_obj) $(usr_obj) $(mem_obj)
	i686-elf-gcc -T kernel/linker.ld -o OSselet.bin \
	  -ffreestanding -O2 -nostdlib \
	  $(lib_obj) $(kernel_obj) $(usr_obj) $(mem_obj) -lgcc

kernel/kernel.o : kernel/kernel.c
	i686-elf-gcc -I $(include) -I $(apps) -I $(mem) -c $^ -o $@ \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra

kernel/boot.o : kernel/boot.asm
	nasm -felf32 kernel/boot.asm -o kernel/boot.o

# libs

$(lib_obj):
	$(foreach var, $(lib_src), \
		i686-elf-gcc -I $(include) -I $(apps) -I $(mem) \
		  -c $(var) -o $(var:.c=.o) \
		  -std=gnu99 -ffreestanding -O2 -Wall -Wextra ;)

$(mem_obj):
	$(foreach var, $(mem_src), \
		i686-elf-gcc -I $(include) -I $(apps) -I $(mem) \
		  -c $(var) -o $(var:.c=.o) \
		  -std=gnu99 -ffreestanding -O2 -Wall -Wextra ;)

# usr

$(usr_obj):
	$(foreach var, $(usr_src), \
		i686-elf-gcc -I $(include) -I $(apps) -I $(mem) \
		  -c $(var) -o $(var:.c=.o) \
		  -std=gnu99 -ffreestanding -O2 -Wall -Wextra ;)

clean :
	rm -f $(kernel_obj) $(lib_obj) $(usr_obj) $(mem_obj)
	rm -f OSselet.bin

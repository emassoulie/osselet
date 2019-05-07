OSselet : linker.ld boot.o kernel.o
	i686-elf-gcc -T linker.ld -o OSselet \
	  -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

kernel.o : kernel.c
	i686-elf-gcc -c kernel.c -o kernel.o \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra	

boot.o : boot.asm
	nasm -f elf32 boot.asm -o boot.o
	
clean :
	rm -f OSselet
	rm -f *.o

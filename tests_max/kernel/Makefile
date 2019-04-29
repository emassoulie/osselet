OSselet : linker.ld boot.o kernel.o
	ld -m elf_i386 -T linker.ld -o OSselet boot.o kernel.o

kernel.o : kernel.c
	gcc -m32 -c kernel.c -o kernel.o \
	-std=gnu99 -ffreestanding -O2 -Wall -Wextra
	
boot.o : boot.asm
	nasm -f elf32 boot.asm -o boot.o
	
clean :
	rm -f OSselet
	rm *.o

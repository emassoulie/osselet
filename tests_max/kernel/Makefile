OSselet : linker.ld boot.o kernel.o screen.o
	i686-elf-gcc -T linker.ld -o OSselet \
	  -ffreestanding -O2 -nostdlib boot.o kernel.o screen.o -lgcc

screen.o : screen.c
	i686-elf-gcc -c screen.c -o screen.o \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra	

kernel.o : kernel.c
	i686-elf-gcc -c kernel.c -o kernel.o \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra	

boot.o : boot.asm
	nasm -f elf32 boot.asm -o boot.o
	
clean :
	rm -f OSselet
	rm -f *.o

kernel : link.ld kasm.o kc.o
	ld -m elf_i386 -T link.ld kasm.o kc.o -o kernel

kc.o : kernel.c
	gcc -m32 -c kernel.c -o kc.o
	
kasm.o : kernel.asm
	nasm -f elf32 kernel.asm -o kasm.o
	
clean :
	rm kernel
	rm *.o

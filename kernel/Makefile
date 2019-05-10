myos.bin : linker.ld boot.o kernel.o string.o printf.o tty.o
	i686-elf-gcc -T linker.ld -o myos.bin \
	  -ffreestanding -O2 -nostdlib boot.o kernel.o lib/string.o lib/printf.o tty.o -lgcc

kernel.o : kernel.c
	i686-elf-gcc -c kernel.c -o kernel.o \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra

printf.o : lib/printf.c
	i686-elf-gcc -c lib/printf.c -o lib/printf.o \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra

string.o : lib/string.c
	i686-elf-gcc -c lib/string.c -o lib/string.o \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra

tty.o : lib/tty.c
	i686-elf-gcc -c lib/tty.c -o lib/tty.o \
	  -std=gnu99 -ffreestanding -O2 -Wall -Wextra

boot.o : boot.s
	i686-elf-as boot.s -o boot.o


clean :
	rm -f *.o
	rm -f myos.bin
	rm -f lib/*.o

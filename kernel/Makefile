myos.bin : linker.ld boot.o kernel.o string.o tty.o
    i686-elf-gcc -T linker.ld -o myos.bin \
      -ffreestanding -O2 -nostdlib boot.o kernel.o string.o tty.o -lgcc

kernel.o : kernel.c
    i686-elf-gcc -c kernel.c -o kernel.o \
      -std=gnu99 -ffreestanding -O2 -Wall -Wextra
    
string.o : string.c
    i686-elf-gcc -c string.c -o string.o \
      -std=gnu99 -ffreestanding -O2 -Wall -Wextra

tty.o : tty.c
    i686-elf-gcc -c tty.c -o tty.o \
      -std=gnu99 -ffreestanding -O2 -Wall -Wextra

boot.o : boot.s
    i686-elf-as boot.s -o boot.o

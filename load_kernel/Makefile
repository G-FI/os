all:run

kernel.bin: kernel_entry.o kernel.o
	i386-elf-ld -o $@ -Ttext 0x100 $^ --oformat binary

kernel_entry.o: kernel_entry.asm
	nasm -f elf $< -o $@

kernel.o:kernel.c
	i386-elf-gcc -ffreestanding -c kernel.c -o kernel.o

bootstrap.bin:bootstrap.asm
	nasm -f bin $< -o $@

os-image: bootstrap.bin kernel.bin
	cat $^ > $@

run:os-image
	qemu-system-i386 -nographic -curses -hda $<

clean:
	rm *.bin *.o

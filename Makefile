#扩展成匹配后面pattern的文件
C_SOURCES = ${wildcard kernel/*.c drivers/*.c}
HEADERS = ${wildcard kernel/*.h drivers/*.h}
#变量值替换（var: .c = .o）
OBJ = ${C_SOURCES:.c=.o}

CFLAGS = -g


run: os-image.bin
	qemu-system-i386  -nographic -curses -fda $<

debug:os-image.bin kernel.elf
	qemu-system-i386 -curses -S -fda os-image.bin &
	gdb -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"



#生成二进制不可调试文件
kernel.bin :boot/kernel_entry.o $(OBJ)
	i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary 

#生成可调试文件
kernel.elf:boot/kernel_entry.o $(OBJ)
	i386-elf-ld -o $@ -Ttext 0x1000 $^ 

os-image.bin: boot/bootstrap.bin kernel.bin
	cat $^ > $@



#编译成目标文件
%.o : %.c ${HEADERS}
	i386-elf-gcc $(CFLAGS) -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin:%.asm
	nasm  -f bin $< -o $@

clean:
	rm -rf *.bin *.o os-image.bin *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o




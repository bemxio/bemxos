SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c lib/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h lib/*.c)
OBJECTS = ${SOURCES:.c=.o cpu/interrupt.o}

bemxOS.bin: boot/bootloader.bin kernel.bin
	cat $^ > bemxOS.bin

kernel.bin: kernel/entry_point.o ${OBJECTS}
	"${CC_PATH}/i386-elf-ld" -Ttext 0x1000 --oformat binary $^ -o $@ 

# for debugging
kernel.elf: kernel/entry_point.o ${OBJECTS}
	"${CC_PATH}/i386-elf-ld" -Ttext 0x1000 $^ -o $@ 

run: bemxOS.bin
	"${QEMU_PATH}/qemu-system-i386.exe" -fda bemxOS.bin

debug: bemxOS.bin kernel.elf
	"${QEMU_PATH}/qemu-system-i386.exe" -s -fda bemxOS.bin &
	"${GDB_PATH}" -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

floppy: bemxOS.bin
	cp bemxOS.bin image.img
	truncate -s 1440K image.img

# generic rules for wildcards
%.o: %.c ${HEADERS}
	"${CC_PATH}/i386-elf-gcc" -g -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.o *.elf *.img
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o cpu/*.o lib/*.o
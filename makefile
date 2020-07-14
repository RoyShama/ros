s-image:kernel.c
	nasm kernel_entry.asm -f elf -o kernel_entry.o
	nasm -fbin boot/main.asm -o main.bin
	rm -rf ./iso
	gcc -ffreestanding -nostdlib -c kernel.c -o kernel.o
	nasm kernel_entry.asm -f elf64 -o kernel_entry.o
	ld -o kernel.bin -Ttext 0x00007E00  kernel_entry.o kernel.o --oformat binary
	cat main.bin kernel.bin > os-image

clean:
	rm main.bin
	rm -rf ./iso
	rm kernel.o
	rm kernel.bin
	rm kernel_entry.o
	rm os-image
run:
	qemu-system-x86_64 os-image

iso:
	rm -rf ./iso
	mkdir iso
	truncate main.bin -s 1200k
	cp main.bin ./iso
	mkisofs -b main.bin -o ./iso/main.iso ./iso

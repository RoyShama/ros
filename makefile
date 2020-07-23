CC=~/.tools/bin/x86_64-elf-gcc
s-image:kernel.c
	nasm kernel_entry.asm -f elf -o kernel_entry.o
	nasm buff.asm -f elf64 -o buff.o
	nasm idt.asm -f elf64 -o idts.o
	nasm -fbin boot/main.asm   -o main.bin
	rm -rf ./iso
	$(CC) -c IO.c -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -nostdlib  -o IO.o
	$(CC) -c stdio.c -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -nostdlib -o stdio.o
	$(CC) -c kernel.c -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -nostdlib -o kernel.o
	$(CC) -c idt.c -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -nostdlib -o idtc.o
	nasm kernel_entry.asm -f elf64 -o kernel_entry.o
	$(CC) -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib  kernel_entry.o kernel.o stdio.o IO.o idtc.o idts.o buff.o -lgcc
	cat main.bin kernel.bin > os-image

clean:
	rm main.bin
	rm -rf ./iso
	rm kernel.o
	rm kernel.bin
	rm kernel_entry.o
	rm os-image
	rm stdio.o
	rm IO.o
	rm buff.o
	rm idts.o
	rm idtc.o
run:
	qemu-system-x86_64 os-image

iso:
	rm -rf ./iso
	mkdir iso
	truncate main.bin -s 1200k
	cp main.bin ./iso
	mkisofs -b main.bin -o ./iso/main.iso ./iso

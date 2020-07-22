[bits 64]
[extern _start]
VID_MEM equ 0xb8000
mov rax, 0x8f658f4b
mov [VID_MEM], rax

mov rax, 0x8f6c8f658f6e8f72
mov [VID_MEM+4], rax
call _start
jmp $



#include "IO.h"
#include "stdio.h"
#include <stdint.h>
typedef struct IDT64{
	uint16_t offset_low;
	uint16_t selector;
	uint8_t ist;
	uint8_t types_attr;
	uint16_t offset_mid;
	uint32_t offset_high;
	uint32_t zero;
}IDT64;


extern IDT64 _idt [256];
extern uint64_t isr1;
extern  void load_idt();


void idt_init(void){
	for(int i = 0; i < 256; ++i){
		_idt[i].zero = 0;
		_idt[i].offset_low = (uint16_t)(((uint64_t)& isr1 & 0x000000000000ffff));
		_idt[i].offset_mid = (uint16_t)(((uint64_t)& isr1 & 0x00000000ffff0000) >> 16);
		_idt[i].offset_high = (uint32_t)(((uint64_t)& isr1 & 0xffffffff00000000) >> 32);
		_idt[i].ist = 0;
		_idt[i].selector = 0x08;
		_idt[i].types_attr = 0x8e;
	}
	outb(0x21,0xfd);
	outb(0xa1,0xff);
	load_idt();
}


extern void isr1_handler(){
	prints(inb(0x60));
	outb(0x20,0x20);
	outb(0xa0,0x20);
}

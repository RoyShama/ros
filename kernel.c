#include "stdio.h"
#include "idt.h"

void _start(void){
	char a[]= "hello world ";
	prints(a);
	idt_init();
	prints(a);
}

#include "IO.h"
void outb(unsigned char* port, unsigned char val){
	*port = val;
}


unsigned char inb(unsigned char* port){
	unsigned char val;
	val = *port;
	return val;
}

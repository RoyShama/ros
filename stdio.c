#include "IO.h"

#define VID_MEM (unsigned char*)0xb8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
static unsigned int vga_offset =0;
void some_function(){
}


void printc(char letter,unsigned int offset){
	char* video_memory =  0xb8000 + offset;
	*video_memory = letter;
	some_function();
}


void prints(char* string){
	int i; 
	for( i = 0; string[i] != '\0'; ++i){
		printc(string[i], 2 * ++vga_offset);
		if(vga_offset > VGA_WIDTH * VGA_HEIGHT){
			vga_offset = 0;
		}
	}
}

#include "IO.h"

#define VID_MEM (unsigned char*)0xb8000
#define test 0
void some_function(){
}


void printc(char letter,unsigned int offset){
	unsigned char* video_memory =  VID_MEM + offset;
	outb(video_memory,letter);
	some_function();
}


void prints(char* string){
	int i; 
	for( i = 0; string[i] != '\0'; ++i){
		printc(string[i], 2 * i);
	}
}

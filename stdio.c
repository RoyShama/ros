#include "stdio.h"

#define VID_MEM 0xb8000
#define test 0
void some_function(){
}


void printc(char letter,unsigned int offset){
	char* video_memory = VID_MEM+offset;
	*video_memory = letter;
	some_function();
}


void prints(char* string){
	int i; 
	for( i = 0; string[i] != '\0'; ++i){
		printc(string[i], 2 * i);
	}
}
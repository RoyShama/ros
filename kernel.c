#define VID_MEM 0xb8000
#define test 0
void some_function(){
}


void print_char(char letter,unsigned int offset){
	char* video_memory = VID_MEM+offset;
	*video_memory = letter;
	some_function();
}


void printf(char* string){
	int i; 
	print_char('h',0);
	for( i = 0; string[i] != '\0'; ++i){
		print_char(string[i], 2 * i);
	}
}


void main(void){
//	char string[] = "hello.";
	printf("hello world.");
}

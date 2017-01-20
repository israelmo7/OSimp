#include "screen.h" // input and output
#include "descriptors.h" // gdt and idt etc.
#include "paging.h" // memory management
#include "libs/math.h" // math library

#define VERSION "\n1.36v\n"


int kmain(void *mbd,unsigned int magic)
{
	screen_clear();
	if (magic!=0x2BADB002){
		screen_print("Invalid multiboot header.");
		return -1;
	}

	gdt_setup();
	idt_setup();
	//Enable Pagination
	enable_paging();
	setup_heap();

	char *a = (char*)malloc(10); // need to fix malloc
	char *b = (char*)malloc(7);
	char *c = (char*)malloc(20);
	
	strcpy(a,"Israel ");
	strcpy(b, "Moshe ");
	strcpy(c, "Dit it!\n");
	
	screen_print(a);
	screen_print(b);
	screen_print(c);

	char* temp = screen_input("Enter text: "); // the problem in realloc -> malloc
	screen_print(temp);
	display_dynamic_memory();

	screen_print(VERSION);
	screen_print("D0N3!\n");

	while(1);
	return 0;
}


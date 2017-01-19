#include "screen.h" // input and output
#include "descriptors.h" // gdt and idt etc.
#include "paging.h" // memory management
#include "libs/math.h" // math library

#define VERSION "\n1.25v\n"


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
	//setup_heap();

	char *a = (char*)malloc(10);
	char *b = (char*)malloc(7);
	char *c = (char*)malloc(20);
	
	strcpy(a,"israel ");
	strcpy(b,"moshe ");
	strcpy(c,"the man!\n");

	screen_print(a);
	screen_print(b);
	screen_print(c);

	//screen_input("Enter text: ");
	display_dynamic_memory();
	screen_print(VERSION);
	screen_print("D0N3!\n");

	while(1);
	return 0;
}


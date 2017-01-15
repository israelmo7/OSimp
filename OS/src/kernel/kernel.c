#include "screen.h" // input and output
#include "descriptors.h" // gdt and idt etc.
#include "memory_m.h" // memory management
#include "libs/math.h" // math library

#define VERSION "\n1.22v\n"


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
	//malloc(10);
	//screen_input("Enter text: ");
	mapper(0x7000);
	screen_print(VERSION);
	screen_print("D0N3!\n");

	while(1);
	return 0;
}


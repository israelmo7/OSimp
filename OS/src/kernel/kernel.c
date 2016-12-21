#include "screen.h"
#include "descriptors.h"
#include "memory_m.h"
#include "libs/math.h"

#define VERSION "1.2v\n"


int kmain(void *mbd,unsigned int magic)
{
	screen_clear();
	if (magic!=0x2BADB002){
		screen_print("Invalid multiboot header.");
		return -1;
	}

	gdt_setup();
	idt_setup();
	screen_print("Enabling Pagination ..\n");
	//Enable Pagination
	enable_paging();
	screen_print("Pagination set!\nD0N3!\n");
	screen_print(VERSION);

	while(1);
	return 0;
}


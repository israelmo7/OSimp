#include "memory_m.h"

//unsigned long* page_d = (unsigned long*) 0x9C000;
unsigned long page_d[1024] __attribute__((aligned(4096));
//unsigned long* page_t = (unsigned long*) 0x9D000;
unsigned long page_t[1024] __attribute__((aligned(4096));

void enable_paging()
{
	unsigned long address = 0;
	unsigned int i;
	
	for(i=0; i < 1024; i++)
	{
		/*
			Create 1024 page tables (each one has 4MB) [SuperVisor|Present]
			PageTable:
				[Physical Address | 0..011]
		*/
		page_t[i] = address | 3;
		address += 4096;
	}
	
	page_d[0] = page_t;
	page_d[0] = page_d[0] | 3;

	for(i=1;i<1024;i++)
	{
		page_d[i] = 0 | 2; // not present
	}

	//Set cr0 paging bit to True.
	asm("	mov %cr0, %eax; \
		or 0x80000000, %eax; \
		mov %eax, %cr0;"); // Set 1 on Paging bit.

	//Set cr3 to PageDirectory address
	asm("	mov %0, %cr3;" :: "a"(page_d));
	//write_cr3(page_d);
}


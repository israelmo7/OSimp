#include "memory_m.h"

unsigned long* page_d = (unsigned long*) 0x9C000;
unsigned long* page_t = (unsigned long*) 0x9D000;

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
		page_d[i] = 0 | 2;
	}

	//Set cr0 paging bit to True.
	asm("	mov %cr0, %eax; \
		or 0x80000000, %eax; \
		mov %eax, %cr0;"); // Set 1 on Paging bit.
	//write_cr0(read_cr0() | 0x80000000);
	//Set cr3 to PageDirectory address
	write_cr3(page_d);
}


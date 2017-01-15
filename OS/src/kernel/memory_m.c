#include "memory_m.h"

//unsigned long* page_d = (unsigned long*) 0x9C000;
unsigned long page_d[1024] __attribute__((aligned(4096)));
//unsigned long* page_t = (unsigned long*) 0x9D000;
unsigned long page_t[1024] __attribute__((aligned(4096)));

#define DIRECTORY_NUMBER(x) (x >> 22)
#define PAGE_NUMBER(x) (x >> 12 & 0x3ff) // 0x3ff = 0b1111111111 (len=10)
#define PAGE_OFFSET(x) (x & 0xfff) 	 // 0xfff = 0b111111111111 (len=12)

void mapper(unsigned long virtual_address)
{
	// virtual address = max_page_offset(0x1000) * page_number + page_offset
	// virtual(p1,o1) = physical(f1,o1)

	unsigned int page_id = PAGE_NUMBER(virtual_address),
		     page_offset = PAGE_OFFSET(virtual_address),
		     directory_id = DIRECTORY_NUMBER(virtual_address);


//	input(0x7000):                                      (page_d[0] + 7) >> 12 + 0
//	unsigned long* phy_addr = (unsigned long*)((page_d[directory_id] + page_id) >> 12 + page_offset);
	unsigned long* phy_addr = (unsigned long*)(page_d[0] + 5);
	intScreen_print(phy_addr,16);
	screen_print("\n");
}
void enable_paging()
{
	screen_print("Enabling Pagination ..\n");
	unsigned long address = 0;
	unsigned int i;
	
	for(i=0; i < 1024; i++)
	{
		/*
			Create 1024 page tables  [SuperVisor|Present]
			PageTable:     20 bit      12 bit
				[Physical Address | 0..011]
		*/
		
		page_t[i] = address | 3;
		address += 4096; //0x1000 
		
	}
	
	page_d[0] = page_t;// | 3;
	page_d[0] |= 3;

	for(i=1;i<1024;i++)
	{
		page_d[i] = 0 | 2; // not present
	}

	//Set cr0 paging bit to True.
	asm("	mov %cr0, %eax; \
		or 0x80000000, %eax; \
		mov %eax, %cr0;"); // Set 1 on Paging bit.

	//Set cr3 to PageDirectory address
	//asm("	mov %0, %cr3;" :: "a"(page_d));
	write_cr3(page_d);
	screen_print("Pagination Set!\n");
}


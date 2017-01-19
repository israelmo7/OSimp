#include "heap.h"
#define DIRECTORY_NUMBER(x) (x >> 22)
#define PAGE_NUMBER(x) (x >> 12 & 0x3ff) // 0x3ff = 0b1111111111 (len=10)
#define PAGE_OFFSET(x) (x & 0xfff) 	 // 0xfff = 0b111111111111 (len=12)

#define PAGE_SIZE 0x1000 //4 MB

typedef struct page_entry
{
	unsigned _flags:12;
	unsigned _address:20;

}pagentry;

//unsigned long* page_d = (unsigned long*) 0x9C000;
pagentry page_d[1024] __attribute__((aligned(4096)));
//unsigned long* page_t = (unsigned long*) 0x9D000;
pagentry page_t[1024] __attribute__((aligned(4096)));



int get_phys_addr(unsigned long virtual_address, unsigned long* physical_address)
{
	pagentry* tempStruct;
	unsigned int directory_number = DIRECTORY_NUMBER(virtual_address);
	unsigned int page_number = PAGE_NUMBER(virtual_address);
	unsigned int offset = PAGE_OFFSET(virtual_address);

	tempStruct = &page_d[directory_number];
	if(!(tempStruct->_flags & 1)) return 0;

	tempStruct = (pagentry*)((tempStruct->_address << 12)+page_number);
	if(!(tempStruct->_flags & 1)) return 0;	

	return ((tempStruct[page_number]._address<<12));//+offset);
}
void page_mapping(unsigned long virtual_address, unsigned int physical_address, unsigned int flags)
{
	pagentry* tempStruct;
	unsigned int directory_number = DIRECTORY_NUMBER(virtual_address);
	unsigned int page_number = PAGE_NUMBER(virtual_address);
	//unsigned int offset = PAGE_OFFSET(virtual_address);

	tempStruct = &page_d[directory_number];
	if(!(tempStruct->_flags & 1)) return;

	tempStruct = (pagentry*)((tempStruct->_address << 12)+page_number);
	if(!(tempStruct->_flags & 1)) return;	

	tempStruct->_address = physical_address;
	tempStruct->_flags = (flags & 1);
}
void page_unmapping(unsigned long virtual_address)
{
	pagentry* tempStruct;
	unsigned int directory_number = DIRECTORY_NUMBER(virtual_address);
	unsigned int page_number = PAGE_NUMBER(virtual_address);
	//unsigned int offset = PAGE_OFFSET(virtual_address);

	tempStruct = &page_d[directory_number];
	if(!(tempStruct->_flags & 1)) return;

	tempStruct = (pagentry*)((tempStruct->_address << 12)+page_number);
	if(!(tempStruct->_flags & 1)) return;	

	tempStruct->_flags &= 0xffe; // no-present [LSB=0]
}
int page_alloc(unsigned long virtual_address, unsigned int size, unsigned int flags)
{
	unsigned int pages = size/PAGE_SIZE; //bytes
	pages += (size % PAGE_SIZE)?1:0;


	

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
		
		page_t[i]._address = address;
		page_t[i]._flags = 3; // 0b011
		address += 4096; //0x1000 
		
	}
	
	page_d[0]._address = page_t;// | 3;
	page_d[0]._flags = 3;

	for(i=1;i<1024;i++)
	{
		page_d[i]._address = 0; // no-addressed - not present
		page_d[i]._flags = 2; // 0b010
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


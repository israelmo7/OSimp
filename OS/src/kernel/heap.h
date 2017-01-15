#ifndef HEAP_C
#define HEAP_C

typedef struct pages
{
	unsigned int* address;
	char isFree;
	unsigned int size;
	
	pages_entries* next;
	
}pages_entries; 


#endif

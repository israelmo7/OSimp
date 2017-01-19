#ifndef HEAP_C
#define HEAP_C

typedef struct dynamic_node
{
	unsigned int* _address;
	//char _used;
	unsigned int _size;
	
	struct dynamic_node* _next;
	
}d_node; 

void setup_heap();
d_node* init_node(unsigned char addr, unsigned int size);
unsigned char* sbrk(unsigned long bytes);
void free(unsigned int addr);
unsigned int malloc(unsigned int size);
unsigned int realloc(unsigned int addr, unsigned int size);
unsigned char fragmentation_manager(unsigned int addr);
void display_dynamic_memory();


void memcpy(char* dst, char* src, int len);
void memset(char* dst, int value, int len);
#endif

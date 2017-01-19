#ifndef HEAP_C
#define HEAP_C

typedef struct dynamic_node
{
	unsigned char* _address;
	//char _used;
	unsigned int _size;
	
	struct dynamic_node* _next;
	
}d_node; 

void setup_heap();
d_node* init_node(unsigned char* addr, unsigned int size);
unsigned char* sbrk(long bytes);
void free(unsigned char* variable);
unsigned char* malloc(unsigned int size);
unsigned int realloc(unsigned char* addr, unsigned int size);
unsigned char fragmentation_manager(unsigned char* addr);
void display_dynamic_memory();
void tester();

void memcpy(char* dst, char* src, int len);
void memset(char* dst, int value, int len);
#endif

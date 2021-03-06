#ifndef HEAP_C
#define HEAP_C

struct dynamic_node
{
	//unsigned char* _address;
	//char _used;
	unsigned int _size;
	
	struct dynamic_node* _next;
	
}__attribute__((__packed__)); 
typedef struct dynamic_node d_node;

void setup_heap();
void init_node(unsigned char* addr, unsigned int size);
unsigned char* sbrk(long bytesize);
void free(unsigned char* addr);
unsigned char* malloc(unsigned int size);
unsigned char* realloc(unsigned char* addr, unsigned int size);
unsigned char fragmentation_manager(unsigned char* addr);
void display_dynamic_memory();
void tester(unsigned char* addr);

void memcpy(char* dst, char* src, int len);
void memset(char* dst, int value, int len);
#endif

#include "heap.h"
#define HEAP_SIZE 0x1000*10




static unsigned char heap[HEAP_SIZE]; // HEAP_SIZE*(32/8)= HEAP_SIZE*4 bytes
static unsigned char *h_pointer = heap;
static d_node* first_node =0;// = (d_node*)init_node(0, 0);


d_node* init_node(unsigned char addr, unsigned int size)
{
	d_node* node;
	node->_address = addr;
	node->_size = size;
	//node->_used = 1;
	node->_next = 0;
	return node;
}
void setup_heap()
{
	first_node = init_node(0, 0);
	screen_print("Heap set!\n");
}
unsigned char* sbrk(long bytes)
{
	if(heap+bytes >= heap && heap+bytes < heap+HEAP_SIZE)
	{
		unsigned char* previous_point = h_pointer;
		h_pointer += bytes;
		return previous_point;
	}
	return 0;
} 
void free(unsigned int addr)
{
	d_node *temp = first_node;
	while(temp)
	{

		if(temp->_address == addr)
		{
			//Need here to manage the dynamic memory
			//And to delete the node

			//temp->_used = 0; // for now
			return;
		}	
	}
	screen_print("Error: Address not found!\n");
}

unsigned int malloc(unsigned int size)
{
	d_node *temp = first_node;
	unsigned char* previous_point;

	while(temp->_next)
	{
		temp = temp->_next;
	}
	if((previous_point = sbrk(size)) == -1)
	{
		screen_print("Error: allocate memory failed!\n");
		return 0;
	}
	
	temp->_next = (d_node*)init_node(previous_point, size);

	return previous_point;
}
unsigned int realloc(unsigned int addr, unsigned int size)
{
	d_node* temp = first_node;
	char* temp_data;
	while(temp)
	{
		if(temp->_address == addr)
		{
			if(temp->_next)
			{
				temp_data = (char*)malloc(strlen(temp->_address));
				strcpy(temp_data, temp->_address);
				break;		
			}
			else // last block
			{
				if(temp->_address+size < HEAP_SIZE &&
				   temp->_address+size >= 0)
				{
					temp->_size = size;
					return temp->_address;
				}
			}		
		}
	}
	if(!temp)
		return -1;



	free(addr);
	//addr = malloc_d(temp_data,size);
	free(temp_data);
	return addr;
}
void display_dynamic_memory()
{
	d_node* temp = first_node;

	while(temp)
	{
		screen_print("|[Addr: ");
		intScreen_print(temp->_address,16);
		screen_print("][Size: ");
		intScreen_print(temp->_size,16);
		screen_print("]\n");

		temp = temp->_next;
	}
}
unsigned char fragmentation_manager(unsigned int addr)
{
	d_node *temp = first_node,
	       *pointer;
	d_node* save_node;	
		
	while(temp && temp->_address != addr) // Find the Header
	{
		temp = temp->_next;
	}	
	if(!temp) return 0; // If not found
	
	pointer = temp->_next; // point to next block
	save_node = temp;      // save the old address	
	free(addr);

	while(pointer)
	{
		memcpy(save_node, pointer->_address, pointer->_size);
		save_node += pointer->_size;
		pointer = pointer->_next;
	}

	return 0;
}

void memcpy(char* dst, char* src, int len)
{
	// dont support NULLs here
	int i=0;
	while(i < len)
	{
		dst[i] = src[i];
	}
}
void memset(char* dst, int value, int len)
{
	// dont support NULLs here
	int i=0;
	while(i < len)
	{
		dst[i] = value;
	}
}



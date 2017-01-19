#include "heap.h"
#define HEAP_SIZE 0x1000*10




static unsigned char heap[HEAP_SIZE]; // HEAP_SIZE*(32/8)= HEAP_SIZE*4 bytes
static unsigned char *h_pointer = heap;
static d_node* first_node =0;// = (d_node*)init_node(0, 0);


d_node* init_node(unsigned char* addr, unsigned int size)
{
	d_node* node;
	node->_address = addr;
	node->_size = size;
	node->_next = 0;
	return node;
}
void setup_heap()
{
	first_node = init_node(0, 0);
	screen_print("Heap set!\n");
}
void tester()
{
	intScreen_print(first_node->_next->_next->_next->_size,10);
}
unsigned char* sbrk(long bytes)
{
	unsigned char* previous_point = h_pointer;
	
	if(h_pointer+bytes >= heap && h_pointer+bytes < heap+HEAP_SIZE)
	{
		h_pointer += bytes;
	}

	return previous_point;
} 
void free(unsigned char* variable)
{
	variable = &variable;
	screen_print("Addr: ");
	intScreen_print(variable,16);
	screen_print(" Blocks: ");
	d_node *temp = first_node;//->_next;
	while(temp)
	{
		intScreen_print(temp->_address,16);//	
		screen_print("\n");
		if(temp->_address == variable)
		{
			sbrk(-temp->_size);
			screen_print("^");
			fragmentation_manager(variable); // Free and prevents from fragmentation
			return;
		}
		temp = temp->_next;	
	}
	screen_print("Error: Address not found!\n");
}

unsigned char* malloc(unsigned int size)
{
	d_node *temp = first_node;
	unsigned char* previous_point;

	while(temp->_next) // Find the last block header
	{
		temp = temp->_next;
	}
	screen_print("");
	if((previous_point = sbrk(size)) == -1) // Check if have free memory
	{
		screen_print("Error: allocate memory failed!\n");
		return 0;
	}

	temp->_next = init_node(previous_point, size);
	return previous_point;
}
unsigned int realloc(unsigned char* addr, unsigned int size)
{
	char makeBigger;
	d_node* temp = first_node;
	char* temp_data;
	while(temp)
	{
		if(temp->_address == addr)
		{
			makeBigger = (size - temp->_size > 0)?1:0;
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
	addr = malloc(size);
	memcpy(addr,temp_data,size);
	free(temp_data);
	return addr;
}
void display_dynamic_memory()
{
	d_node* temp = first_node;

	while(temp)
	{
		screen_print("[Addr: ");
		intScreen_print(temp->_address,16);
		screen_print("][Size: ");
		intScreen_print(temp->_size,10);
		screen_print("]\n");

		temp = temp->_next;
	}
}
unsigned char fragmentation_manager(unsigned char* addr)
{
	d_node *temp = first_node, *saver, *save_saver;
		
	while(temp && temp->_address != addr) // Find the Header
	{
		saver = temp;
		temp = temp->_next;
	}	
	if(!temp) return 0; // If not found
	
			     // saver is one before the block we want to remove (=temp)
	save_saver = saver;
	saver = temp->_next; // temp holds the location of the old address.
	screen_print("*");
	while(saver)
	{
		memcpy(temp, saver->_address, saver->_size);
		temp += saver->_size;
		save_saver = saver;
		saver = saver->_next;
	}
	save_saver->_next = 0;
	return 0;
}

void memcpy(char* dst, char* src, int len)
{
	// dont support NULLs here
	int i=0;
	while(i < len && src[i])
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



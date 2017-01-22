#include "heap.h"
#define HEAP_SIZE 0x1000*4


static unsigned char heap[HEAP_SIZE]; // HEAP_SIZE*(32/8)= HEAP_SIZE*4 bytes
static unsigned char *h_pointer = heap+sizeof(d_node);
static d_node* first_node =0;// = (d_node*)init_node(0, 0);


void init_node(unsigned char* addr, unsigned int size) // size in bytes
{
	//	 [    header     ] [   data  ]
	//Block: [size:4 | next:8] [data:size]

	memcpy(addr, &size, sizeof(size));   // make the size variable in the header 
	memset(addr+sizeof(size), 0, size+sizeof(d_node*)); //  make the next variable & the data to zero

}
void setup_heap()
{
	init_node(heap, 0);
	first_node = heap;	
	screen_print("Heap set and start in ");
	intScreen_print(heap,16);
	screen_print("h\n");
}
void tester(unsigned char* addr)
{
	d_node* temp = addr;
	screen_print("[Address: ");
	intScreen_print(temp,16);
	screen_print("][Size: ");
	intScreen_print(temp->_size,10);
	screen_print("][Next: ");
	intScreen_print(temp->_next,16);
	screen_print("]\n");
}
unsigned char* sbrk(long bytesize)
{
//	The Function works well, return the next address in the Heap memory.

	unsigned char* previous_point = h_pointer;

	bytesize += (bytesize <0)? -sizeof(d_node) : sizeof(d_node);

	if(h_pointer+bytesize > heap && h_pointer+bytesize < heap+HEAP_SIZE)
	{
		h_pointer += bytesize;
	}
	else
	{
		screen_print("Error: has no free memory left\n"); 
		previous_point = 0;
	}

	return previous_point;
} 
void free(unsigned char* addr)
{
	addr -= sizeof(d_node); // To header

	d_node *temp = first_node->_next;
	while(temp)
	{
		if(temp == addr)
		{
			sbrk(-temp->_size);
			if(!fragmentation_manager(addr)) // Free and prevents from fragmentation
				screen_print("Error in fragmentation_manager\n");
			return;
		}
		temp = temp->_next;	
	}
	screen_print("Free function Error: Address not found!\n");
}

unsigned char* malloc(unsigned int size)
{

	d_node *temp = first_node,*saver=0;
	unsigned char* previous_addr;

	while(temp) // Find the last block header
	{
		saver = temp;
		temp = temp->_next;		//temp is the last Block
	}
	screen_print("");
	previous_addr = sbrk(size);

	if(!previous_addr) // Check if have free memory
	{
		screen_print("Error: allocate memory failed!\n");
		return 0;
	}

	init_node(previous_addr, size);
	saver->_next = previous_addr;

	return previous_addr+sizeof(d_node);
}
unsigned char* realloc(unsigned char* addr, unsigned int size)
{
	addr -= sizeof(d_node); // To Header

	d_node* temp = first_node;
	char* temp_data;

	while(temp)
	{
		/*
		screen_print("\nAddressTemp => ");
		intScreen_print(addr,16);
		screen_print("    ");
		intScreen_print(temp,16);
		screen_print(" <= AddressRealloc\n");
		*/
		if(temp == addr)
		{
			if(temp->_size >= size)
				return addr;
			if(temp->_next)
			{
				//screen_print("Middle\n");
				temp_data = (char*)malloc(temp->_size+sizeof(d_node))-sizeof(d_node);
				memcpy(temp_data, temp,temp->_size+sizeof(d_node));
				break;		
			}
			else // last block
			{
				//screen_print("Last\n");
				if(sbrk(size-temp->_size))
				{
					/*
					screen_print("\nAddressReturn => ");
					intScreen_print(addr,16);
					screen_print("\n");
					*/
					temp->_size = size;
					return addr+sizeof(d_node);
				}
				screen_print("Error: have no free memory\n");
				return 0;
			}		
		}
		temp = temp->_next;
	}
	if(!temp)
	{
		screen_print("\nError: address not found\n");
		return 0;
	}


	free(addr+sizeof(d_node));
	addr = malloc(size)-sizeof(d_node);
	memcpy(addr,temp_data,size+sizeof(d_node));
	free(temp_data);
	return addr;
}
void display_dynamic_memory()
{
	d_node* temp = first_node;//->_next;
	while(temp)
	{
		tester(temp);
		temp = temp->_next;
	}
	screen_print("\n");
}
unsigned char fragmentation_manager(unsigned char* addr)
{
	d_node *node2free = first_node, *node1before, *node1after;
		
	while(node2free && node2free != addr) // Find the Header
	{
		node1before = node2free;
		node2free = node2free->_next;
	}	
	if(!node2free) return 0; // If not found

			     //   [first_node]->...->[node1before]->[node2free]->[node1after]->...->[NULL]

			            	// node2free is the node we have to free
				  	// node1before is one before the block we want to remove
	node1after = node2free->_next; // node1after is node after the node we try to find
	
	while(node1after)
	{
		memcpy(node2free, node1after, node1after->_size+sizeof(d_node));
		//memcpy(node2free, node1after->_size, sizeof(node1after->_size));
		
		node2free->_size = node1after->_size;
		node2free->_next = node2free + node2free->_size + sizeof(d_node);

		node2free += sizeof(d_node)+node2free->_size;		

		node1before = node2free;
		node1after = node1after->_next;
	}
	node1before->_next = 0;
	return 1;
}

void memcpy(char* dst, char* src, int len)
{
	// dont support NULLs here
	int i=0;
	while(i < len)
	{
		dst[i] = src[i++];
	}
}
void memset(char* dst, int value, int len)
{
	// dont support NULLs here
	int i=0;
	while(i < len)
	{
		dst[i++] = value;
	}
}



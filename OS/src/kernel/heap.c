#include "heap.h"
#define HEAP_SIZE 0x1000*4


static unsigned char heap[HEAP_SIZE]; // HEAP_SIZE*(32/8)= HEAP_SIZE*4 bytes
static unsigned char *h_pointer = heap+sizeof(int);
static d_node* first_node =0;// = (d_node*)init_node(0, 0);


unsigned char* init_node(unsigned char* addr, unsigned int size) // size in bytes
{
	memcpy(addr, &size, sizeof(size));   // make the size variable in the header 
	memset(addr+sizeof(size), 0, size+sizeof(d_node*)); //  make the next variable & the data to zero
	
	return addr;
}
void setup_heap()
{
	first_node = init_node(heap, 0);
	screen_print("Heap set and start in ");
	intScreen_print(heap,16);
	screen_print("h\n");
}
void tester()
{
	char* node = 0;
	intScreen_print(sizeof(d_node),10);
}
unsigned char* sbrk(long bytes)
{
	unsigned char* previous_point = h_pointer;
	
	if(h_pointer+bytes+sizeof(d_node) >= heap && h_pointer+bytes+sizeof(d_node) < heap+HEAP_SIZE)
	{
		h_pointer += bytes+sizeof(d_node);
	}
	else
	{
		screen_print("Error: has no free memory left\n"); 
		previous_point = 0;
	}

	return previous_point;
} 
void free(unsigned char* variable)
{
	d_node *temp = first_node;//->_next;
	while(temp)
	{
		if(temp == variable)
		{
			sbrk(-temp->_size); // +*+*+*+*+*
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
	unsigned char* previous_addr;

	while(temp->_next) // Find the last block header
		temp = temp->_next;

	screen_print("");
	previous_addr = sbrk(size);

	if(!previous_addr) // Check if have free memory
	{
		screen_print("Error: allocate memory failed!\n");
		return 0;
	}
	temp->_next = init_node(previous_addr, size);


	return previous_addr;
}
unsigned char* realloc(unsigned char* addr, unsigned int size)
{

	d_node* temp = first_node;
	char* temp_data;

	while(temp)
	{
		screen_print("Address1: ");
		intScreen_print(temp,16);
		screen_print("\n");

		if(temp == addr)
		{
			if(temp->_next)
			{
				temp_data = (char*)malloc(temp->_size+sizeof(d_node));
				memcpy(temp_data, temp,temp->_size+sizeof(d_node));
				break;		
			}
			else // last block
			{
				if(temp+temp->_size+sizeof(d_node)+size < HEAP_SIZE+temp &&
				   temp+temp->_size+sizeof(d_node)+size >= 0)
				{
					temp->_size = size;
					return temp+sizeof(d_node);
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


	free(addr);
	addr = malloc(size);
	memcpy(addr,temp_data,size+sizeof(d_node));
	free(temp_data);
	return addr;
}
void display_dynamic_memory()
{
	d_node* temp = first_node;

	while(temp)
	{
		screen_print("[RealAddress: ");
		intScreen_print(temp,16);
		screen_print("][Addr: ");
		intScreen_print(temp+temp->_size,16);
		screen_print("][Size: ");
		intScreen_print(temp->_size,10);
		screen_print("][Next: ");
		intScreen_print(temp->_next,16);
		screen_print("]\n");

		temp = temp->_next;
	}
}
unsigned char fragmentation_manager(unsigned char* addr)
{
	d_node *node2free = first_node, *node1before, *node1after;
		
	while(node2free && node2free != addr) // Find the Header
	{
		node1after = node2free;
		node2free = node2free->_next;
	}	
	if(!node2free) return 0; // If not found

			     //   [first_node]->...->[Save_Saver]->[Temp]->[Saver]->...->[NULL]

			            	// node2free is the node we have to free
	node1before = node1after;  	// node1before is one before the block we want to remove (=node2free)
	node1after = node2free->_next; // node1after is node after the node we try to find
	
	while(node1after)
	{

		memcpy(node2free, node1after, node1after->_size+sizeof(d_node)); // node1after[address] -> temp
		node2free = node2free + node1after->_size; 			    // make it points to address for the next block
		node1before = node1after; 				    
		
		node1after = node1after->_next;;
	}
	node1before->_next = 0;
	return 0;
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



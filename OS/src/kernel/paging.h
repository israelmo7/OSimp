#ifndef MEMORY_M_H
#define MEMORY_M_H


extern void write_cr3(unsigned long* value);
void enable_paging();
int get_phys_addr(unsigned long virtual_address, unsigned long* physical_address);
int page_alloc(unsigned long virtual_address, unsigned int size, unsigned int flags);
void page_mapping(unsigned long virtual_memory, unsigned int physical_address, unsigned int flags);
void page_unmapping(unsigned long virtual_address);
#endif

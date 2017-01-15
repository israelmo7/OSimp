#ifndef MEMORY_M_H
#define MEMORY_M_H


extern void write_cr3(unsigned long* value);
void enable_paging();
void mapper(unsigned long virtual_address);

#endif

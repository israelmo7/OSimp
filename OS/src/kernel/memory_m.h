#ifndef MEMORY_M_H
#define MEMORY_M_H


extern void write_cr3(unsigned long* value);
extern void write_cr0(unsigned long value);
extern unsigned long read_cr3();
extern unsigned long read_cr0();


void enable_paging();

#endif

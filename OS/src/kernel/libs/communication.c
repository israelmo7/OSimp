#include "communication.h"

void outb(unsigned short port, unsigned char value)
{
	asm volatile("outb %1, %0" :: "dN" (port), "a" (value));
}
unsigned char inb(unsigned short port)
{
	unsigned char ret =0;

	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));

	return ret;
}

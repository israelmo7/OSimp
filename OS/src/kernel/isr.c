#include "isr.h"

void(*callbacks[MAX_IRQ])();

void isr_handler(ans_packet args ,unsigned int interruptNumber)
{
	screen_print("Interrupt received: ");	
	intScreen_print(interruptNumber, 16);
	screen_print("\n");
}
void irq_handler(ans_packet args, unsigned int irqNumber)
{
	outb(0x20, 0x20); //Ack to the Main PIC

	if(irqNumber >= 8)
	{
		outb(0xA0, 0x20); //Ack to the Slave PIC
	}
	if(callbacks[irqNumber])
	{
		(*callbacks[irqNumber])();
	}
	else
	{
		screen_print("IRQ received: ");	
		intScreen_print(irqNumber, 16);
		screen_print("\n");
	}
}
void set_irq_func(unsigned short index, void (*callback_func)())
{
	screen_print("IRQ ");
	intScreen_print(index,10);
	screen_print(" Function Set!\n");
	callbacks[index] = callback_func;
}
void exec_func(unsigned short index)
{
	(*callbacks[index])();
}

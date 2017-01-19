#include "isr.h"

void(*callbacks[MAX_IRQ])();

//irq = hardware interrupt
/*
	The function handle the isr that commes
	Input:
		ans_packet - struct of registers
		interruptNumber - the interrupt number
	Output:
		none
*/
void isr_handler(ans_packet args ,unsigned int interruptNumber)
{
	screen_print("Interrupt received: ");	
	intScreen_print(interruptNumber, 16);
	screen_print("\n");
}
/*
	The function handle the irq that commes
	Input:
		ans_packet - struct of registers
		irq_number - the IRQ number
	Output:
		none
*/
void irq_handler(ans_packet args, unsigned int irqNumber)
{
	outb(0x20, 0x20); //Ack to the Main PIC

	if(irqNumber >= 8) // slave IRQ
	{
		outb(0xA0, 0x20); //Ack to the Slave PIC
	}
	if(callbacks[irqNumber]) // if there function for this irq
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
/*
	The function sets function for some IRQ
	Input:
		index - number that point to the func
		callback_func - func to set
	Output:
		none
*/
void set_irq_func(unsigned short index, void (*callback_func)())
{
	screen_print("*IRQ ");
	intScreen_print(index,10);
	screen_print(" Function Set!\n");
	callbacks[index] = callback_func;
}
/*
	The function executes the function from the callbacks list
	Input:
		index - number that point to the func
	Output:
		none
*/
void exec_func(unsigned short index)
{
	(*callbacks[index])();
}

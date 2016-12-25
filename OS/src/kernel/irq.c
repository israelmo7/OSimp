#include "irq.h"

void watch()
{
	/*
	static unsigned int time =0;
	
	if(time % 100 == 0)
	{
		screen_print("Tick(");
		intScreen_print(time / 1000,10); // Count in Seconds.
		screen_print(")\n");
	}
	time += 55;
	*/
}
void irq_setup()
{
	screen_print("IRQ setting ..\n");
	set_irq_func(0,watch); // Set interrupt1 handler to watch function
	set_irq_func(1,interrupt_keyboard); // " " " " keyboard "
	screen_print("IRQ set!\n");
}

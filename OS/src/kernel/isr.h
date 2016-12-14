#ifndef ISR_H
#define ISR_H
#define MAX_IRQ 16
#include "screen.h"
#include "libs/communication.h"
struct answer_packet
{
	unsigned int ds; //Data segment
	unsigned int di; //Destination index
	unsigned int si; //Source index
	unsigned int bp; //Base pointer
	unsigned int sp; //Stack pointer
	unsigned int bx; //Register B
	unsigned int dx; //Register D
	unsigned int cx; //Register C
	unsigned int ax; //Register A

};
typedef struct answer_packet ans_packet;

void isr_handler(ans_packet args ,unsigned int interruptNumber);
void irq_handler(ans_packet args, unsigned int irqNumber);
void set_irq_func(unsigned short index, void (*callback_func)());
void exec_func(unsigned short index);

#endif


#ifndef DESCRIPTORS_H
#define DESCRIPTORS_H
#include "libs/communication.h"
#include "isr.h"
#include "irq.h"

void pic_init();
void gdt_setup();
void idt_setup();
void irq_setup();
void watch();
#endif


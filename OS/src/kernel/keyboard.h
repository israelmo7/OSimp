#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "screen.h"
#include "libs/communication.h"



void set_input_mode_flag(char flag);
char getchar();
void interrupt_keyboard();
#endif

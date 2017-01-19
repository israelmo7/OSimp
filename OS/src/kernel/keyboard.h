#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "screen.h"
#include "libs/communication.h"

char* getBuffer();
void waitforpress();
char get_input_mode_flag();
void set_input_mode_flag(char flag);
char getchar();
void interrupt_keyboard();
#endif

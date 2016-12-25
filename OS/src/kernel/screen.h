#ifndef SCREEN_H
#define SCREEN_H
#include "libs/string.h"

void screen_clear();
void screen_print(char* string);
void screen_scroll();
void intScreen_print(int number, int base);
char* screen_input(char* text);
void putchar(unsigned char c);

#endif

#ifndef RUNTIME_H
#define RUNTIME_H
#define NULL 0
#include "math.h"

int strlen(const char *str);
int intlen(int num);
int strcmp(const char *a, const char *b);
char * itoa( int value, char * str, int base );
int atoi(const char* str);
int hex2dec(int num);
#endif

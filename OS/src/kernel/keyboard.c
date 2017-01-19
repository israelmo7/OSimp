#include "keyboard.h"

char input_mode_flag = 0;

unsigned short counter =0;
static char* buffer =0;
char locker =0;	
unsigned char uKey_code[128] = 
{
  0,  27, '!', '@', '#', '$', '%', '^', '&', '*',	/* 9 */
  '(', ')', '_', '+', '\b',	/* Backspace */
  '\t',			/* Tab */
  'Q', 'W', 'E', 'R',	/* 19 */
  'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\r',		/* Enter key */
  0,			/* 29   - Control */
  'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',	/* 39 */
  '\"', '~',   0,		/* Left shift */
  '|', 'Z', 'X', 'C', 'V', 'B', 'N',			/* 49 */
  'M', '<', '>', '?',   0,					/* Right shift */
  '*',
  0,	/* Alt */
  ' ',	/* Space bar */
  0,	/* Caps lock */
  0,	/* 59 - F1 key ... > */
  0,   0,   0,   0,   0,   0,   0,   0,
  0,	/* < ... F10 */
  0,	/* 69 - Num lock*/
  0,	/* Scroll Lock */
  0,	/* Home key */
  0,	/* Up Arrow */
  0,	/* Page Up */
  '-',
  0,	/* Left Arrow */
  0,
  0,	/* Right Arrow */
  '+',
  0,	/* 79 - End key*/
  0,	/* Down Arrow */
  0,	/* Page Down */
  0,	/* Insert Key */
  0,	/* Delete Key */
  0,   0,   0,
  0,	/* F11 Key */
  0,	/* F12 Key */
  0,	/* All other keys are undefined */
};

unsigned char lKey_code[128] =
{
  0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\r',		/* Enter key */
  0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
  '\'', '`',   0,		/* Left shift */
  '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   'r',					/* Right shift */
  '*',
  0,	/* Alt */
  ' ',	/* Space bar */
  0,	/* Caps lock */
  0,	/* 59 - F1 key ... > */
  0,   0,   0,   0,   0,   0,   0,   0,
  0,	/* < ... F10 */
  0,	/* 69 - Num lock*/
  0,	/* Scroll Lock */
  0,	/* Home key */
  0,	/* Up Arrow */
  0,	/* Page Up */
  '-',
  0,	/* Left Arrow */
  0,
  0,	/* Right Arrow */
  '+',
  0,	/* 79 - End key*/
  0,	/* Down Arrow */
  0,	/* Page Down */
  0,	/* Insert Key */
  0,	/* Delete Key */
  0,   0,   0,
  0,	/* F11 Key */
  0,	/* F12 Key */
  0,	/* All other keys are undefined */
};
//char shift_bit; // flag for shift state

char getchar()
{
	unsigned char scan_code = inb(0x60); // port to the keyboard

	return uKey_code[scan_code];
}

void set_input_mode_flag(char flag)
{
	input_mode_flag = flag;
}
char get_input_mode_flag()
{
	return input_mode_flag;
}
void interrupt_keyboard()
{

	unsigned char scan_code = inb(0x60);
	char toPrint;
	if(scan_code & 0x80) // check if released
	{
		//released
		if(scan_code-0x80 == 54 || scan_code-0x80 == 42)
		{
			//shift_bit = 0;
		}	
	}
	else
	{
		locker = 0;
		//pressed
		if(scan_code == 54 || scan_code == 42)
		{
			//shift_bit = 1;
		}
		return;
	}
	
	if (scan_code == 156) // Enter pressed
	{
		input_mode_flag = 0;
		counter = 0;
		screen_print("\n");
		buffer[((counter)?counter:9)] = 0;
		//screen_print(buffer);
		//screen_print("\n");
	}	
	else
	{		

		toPrint = uKey_code[scan_code];
	
		if(input_mode_flag)
		{
			if(!buffer)
				buffer = (char*)malloc(2);
			else
				buffer = (char*)realloc(buffer,counter+1);
			putchar_k(toPrint);
			buffer[counter++] = toPrint;
			buffer[counter] = 0;

		}
	}
}
char* getBuffer()
{
	return buffer;
}
void waitforpress()
{
	locker = 1;
	while(locker);
}

#include "screen.h"

unsigned char *vidmem=(unsigned char *)0xb8000; // Video Memory

unsigned char x=0,y=0; // [x, y] | [line offset, line number]

void screen_clear(){
	int i;
	for(i=0;i<4000;i+=2)
	{
		vidmem[i]=0x20; // empty char
		vidmem[i+1]=0x07; // color
	}
	x=0;
	y=0;
}

void screen_scroll(){
	int i;
	for(i=160;i<4000;i+=2){
		vidmem[i-160]=vidmem[i]; // go back 2 lines
	}
}
void putchar_k(unsigned char c)
{
	if(y==25) // end of lines
	{
		screen_scroll();
		y=24;
	}
	if(c > 0x1f && c != 0x7f) // is Char
	{
		vidmem[2*(x+y*80)]= c;
		vidmem[2*(x+y*80)+1]=0x02; //color
		x++;
		if(x==80)//endofline
		{ 
			y++;
			x=0;
		}
	}
	else
	{
		switch(c)
		{
			case 0x08: // Delete Char
				if(x!=0)
				{
					x--;
				}
				break;
			case 0x09: // Tab
				x+=4;
				if(x<80)
				{
					break;
				}
			case 0x0a: //New Line
				x=0;
				y++;
				break;
		}
	}
}
void screen_print(char* string)
{	
	int i=0;
	while(string[i]) // Until the nullByte
	{ 
		putchar_k(string[i++]);		
	}
}
void screen_printf(int number_of_strings, ... )
{	
	/*
	va_list ap;
	va_start(ap, number_of_strings);

	while(number_of_strings--)
	{
		char* string = va_arg(ap, char*);
		int i=0;
		while(string[i]) // Until the nullByte
		{ 
			putchar(string[i++]);		
		}
	}
	va_end(ap);
	*/
}
void intScreen_print(int number,int base)
{
	char buffer[10];
	if(itoa(number,buffer,base)) // convert to string
		screen_print(buffer); // and print to screen
	else
		screen_print("Error: Itoa function");
	//screen_print("\n");
}
char* screen_input(char* text)
{
	screen_print(text);
	set_input_mode_flag(1); // set input mode
	while(get_input_mode_flag()); 
	return getBuffer();
}


#include "screen.h"

unsigned char *vidmem=(unsigned char *)0xb8000; // Video Memory

unsigned char x=0,y=0; // Texting Pointer

void screen_clear(){
	int i;
	for(i=0;i<4000;i+=2)
	{
		vidmem[i]=0x20;
		vidmem[i+1]=0x07;
	}
	x=0;
	y=0;
}

void screen_scroll(){
	int i;
	for(i=160;i<4000;i+=2){
		vidmem[i-160]=vidmem[i];
	}
}
void putchar(unsigned char c)
{
	if(y==25)
	{
		screen_scroll();
		y=24;
	}
	if(c > 0x1f && c != 0x7f)
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
				if(x>=80)
				{
					x=0;
					y++;
				}
				break;
			case 0x0a: //New Line
				x=0;
				y++;
				break;
		}
	}
}
void screen_print(char *string){
	int i=0;
	while(string[i])
	{ 
		putchar(string[i++]);		
	}
}
void intScreen_print(int number,int base)
{
	char buffer[10];
	if(itoa(number,buffer,base))
		screen_print(buffer);
	else
		screen_print("Error: Itoa function");
	screen_print("\n");
}
char* screen_input(char* text)
{
	screen_print(text);
	set_input_mode_flag(1);
	while(!buffer[0]);
	
}


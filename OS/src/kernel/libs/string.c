#include "string.h"

int strlen(const char *str)
{
	int counter = -1;
	while(str[++counter]);
	return counter;
}
int intlen(int num)
{
	int count = 1;

	for(;num > 9; count ++, num/=10);

	return count;
}
int strcmp(const char *a, const char *b)
{
	for(int i =0; a[i]; i++)
	{
		if(a[i] - b[i] != 0)
		{
			return a[i] - b[i];
		}
	}
	return 0;
}
/*
void itoa(int num, char* buffer)
{

	int number_len = 1,i,tempNum = num,
	    temp = 1;

	while(tempNum > 9)
	{
		tempNum /= 10;
		temp *= 10;
		number_len ++;
	}

	for(i=0; i <number_len; i++)
	{
		buffer[i] = (num / temp % 10) + '0';
		temp /= 10;
	}
	buffer[i] = NULL;
} */
char * itoa( int value, char * str, int base )
{
	char * rc;
	char * ptr;
	char * low;
	// Check for supported base.
	if ( base < 2 || base > 36 )
	{
		*str = '\0';
		return str;
	}
	rc = ptr = str;
	// Set '-' for negative decimals.
	if ( value < 0 && base == 10 )
	{
		*ptr++ = '-';
	}
	// Remember where the numbers start.
	low = ptr;
	// The actual conversion.
	do
	{
	// Modulo is negative for negative value. This trick makes abs() unnecessary.
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
		value /= base;
	} while ( value );
	// Terminating the string.
		*ptr-- = '\0';
	// Invert the numbers.
	while ( low < ptr )
	{
		char tmp = *low;
		*low++ = *ptr;
		*ptr-- = tmp;
	}
	return rc;
}
int hex2dec(int num)
{
	const unsigned int LEN = intlen(num);
	int result=0,i=0,cnt=0,temp = power(10,LEN);

	for(i; i < LEN; i++)
	{
		result += power(((num / temp) % 10),cnt++);
		temp /= 10;
	}

	return result;
	
}
int atoi(const char* str)
{
	int LEN = strlen(str),temp = 1,retValue=0,i=0;
	for(;i < LEN;i++)
	{
		retValue += str[LEN-i]*temp;
		temp *=10;
	}
	return retValue;
}
void strcat(char* dest, char* src)
{
	int i =0,j=0;
	while(dest[i]) 
		i++;
	
	while(src[j])
		dest[i++] = src[j++];
	dest[i] = src[j];
}
void strcpy(char* dest, char* src)
{
	int i=0;
	while(src[i])
		dest[i] = src[i++];	
	dest[i] = src[i];	
}

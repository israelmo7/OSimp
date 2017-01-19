#include "math.h"

int power(int number, int pow)
{
	int result = 1,
		i;
	
	for(i=0; i < pow; i++)
	{
		result *= number;
	}
	
	return ((number > 0)? result: 1/result);
	
}	

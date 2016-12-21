#include "math.h"

int pow(int number, int pow)
{
	int result = 1,
		i=0;
	
	for(i; i < pow; i++)
	{
		result *= number;
	}
	
	return ((number > 0)? result: 1/result);
	
}	

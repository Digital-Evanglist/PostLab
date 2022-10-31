#include "economyClass.h"

int economyFunction(_Bool array[], int seatNo)
{
	if (array[seatNo - 1] == 1)
	{
		
		return 0;
	}
	else
	{
		array[seatNo - 1] = 1;
		return 1;
	}
}
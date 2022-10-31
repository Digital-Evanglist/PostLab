#include<stdio.h> 
#include<stdbool.h>
#include"FirstClass.h"

int firstClassFun(_Bool seats[], int seatNumber)
{
	if (seats[seatNumber - 1] == 0)
	{
		seats[seatNumber - 1] = 1;
		return 1;
	}
	else
	{
		return 0;
	}
}
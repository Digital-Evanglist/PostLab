#include<stdio.h>
#include<conio.h>
#include "economyClass.h"
#include "firstClass.h"

#define SIZE 100

void printSeats(_Bool[], int);
void boardingPass(int, int);
int checkSeats(_Bool[], int);
void printAvailabeSeats(int, int);


int main()
{
	_Bool flag = 1;
	int seatNumber;
	_Bool seats[SIZE] = {0};
	int firstClassSeats = 30;
	int economyClassSeats = 70;

	

	int choice;
	do
	{
		printf("\t\t------------------------------\n");
		printf("\t\t|Type 0 to exit\n");
		printf("\t\t|Type 1 for First Class Section\n");
		printf("\t\t|Type 2 for Economy Class Section\n");
		printf("\t\t|Type 3 To display Seats Map\n");
		printf("\t\t|Type 4 to display Available Seats\n");
		printf("\t\t-------------------------------\n");

		printf("\t\t---------------------------\n");
		printf("\t\t|Airline Reservation System|\n");
		printf("\t\t---------------------------\n");


		printf("\n\t\tSelect type of Class : ");
		scanf_s("%d", &choice);
		
		if (choice == 0)
		{
			break;
		}
		else if (choice == 1)
		{
			if (checkSeats(seats, choice))
			{
				while (flag)
				{
					printf("\t\tEnter seat number (1-30) : ");
					scanf_s("%d", &seatNumber);
					if (seatNumber >= 1 && seatNumber <= 30)
					{
						flag = 0;
					}
					else
					{
						printf("\t\tEnter Seat Number with in given range\n");
					}
				}
				flag = 1;

				int bookedSeat = firstClassFun(seats,seatNumber);
				if (bookedSeat == 1)
				{
					firstClassSeats--;
					boardingPass(seatNumber, choice);
				}
				else
				{
					printf("\t\tSeat Number %d is already booked\n",seatNumber);
				}
			}
			else
			{
				printf("\t\t----------------------------------------------------\n");
				printf("\t\t|All seats of First Class Section have been Booked|\n");
				printf("\t\t----------------------------------------------------\n");
			}
		}
		else if (choice == 2)
		{
			if (checkSeats(seats, choice))
			{
				while (flag)
				{
					printf("\t\tEnter seat number (31-100) : ");
					scanf_s("%d", &seatNumber);
					if (seatNumber >= 31 && seatNumber <= 100)
					{
						flag = 0;
					}
					else
					{
						printf("\t\tEnter Seat Number with in given range\n");
					}
				}
				flag = 1;

				int bookedSeat = economyFunction(seats, seatNumber);
				if (bookedSeat == 1)
				{
					economyClassSeats--;
					boardingPass(seatNumber, choice);
				}
				else
				{
					printf("\t\tSeat Number %d is already booked\n",seatNumber);
				}
			}
			else
			{
				printf("\t\t----------------------------------------------------\n");
				printf("\t\t|All seats of Economy Class Section have been Booked|\n");
				printf("\t\t----------------------------------------------------\n");
			}
		}
		else if (choice == 3)
		{
			printSeats(seats, SIZE);
		}
		else if (choice == 4)
		{
			printAvailabeSeats(firstClassSeats, economyClassSeats);
		}
		else
		{
			printf("\t\t------------\n");
			printf("\t\t|Invalid Choice|\n");
			printf("\t\t----------------");
		}
		printf("\t\tClearing the screen\n\t\t");
		Sleep(1500);
		system("cls");

	} while (choice != 0);
	printf("\n");
	printf("\t\t---------------------\n");
	printf("\t\t|Have a nice Journey|\n");
	printf("\t\t---------------------\n");
	return 0;
}


void printSeats(_Bool array[], int size)
{
	printf("\n");
	printf("\t\t--------------\n");
	printf("\t\t|Seats Status|\n");
	printf("\t\t--------------\n");

	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n\t\t");
		}
		printf("%d ", array[i]);
	}
	printf("\n");
}

void boardingPass(int seatNo, int seatStatus)
{
	printf("\n");
	printf("\t\t---------------\n");
	printf("\t\t|Boarding Pass|\n");
	printf("\t\t---------------\n");
	printf("\t\t-----------------\n");
	printf("\t\t|Seat Number = %d|\n", seatNo);
	printf("\t\t-----------------\n");

	if (seatStatus == 1)
	{
		printf("\t\t-------------\n");
		printf("\t\t|First Class|\n");
		printf("\t\t-------------\n");
	}
	else
	{
		printf("\t\t---------------\n");
		printf("\t\t|Economy Class|\n");
		printf("\t\t---------------\n");
	}
}



// This function checks wheather all the seats are booked or not
int checkSeats(_Bool array[], int choice)
{
	int i = 0;
	if (choice == 1)
	{
		for (int i = 0; i <= 29; i++)
		{
			if (array[i] != 1)
			{
				return 1;
			}
		}
	}
	else
	{
		for (i = 30; i <= 99; i++)
		{
			if (array[i] != 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

void printAvailabeSeats(int firstSeatsNo, int economySeatsNo)
{
	printf("\n");
	printf("\t\t------------------------\n");
	printf("\t\t|Available Seats are : |\n");
	printf("\t\t-----------------------\n");
	
	printf("\t\t------------------------\n");
	printf("\t\t|First Class Seats = %d\n",firstSeatsNo);
	printf("\t\t|Economy Class Seats = %d\n", economySeatsNo);
	printf("\t\t-------------------------\n");
}
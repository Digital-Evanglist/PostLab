#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"FirstClass.h"
#include"economyClass.h"

int main()
{
    srand(time(NULL));
	_Bool seats[100] = { 0 };
	int seatNumber, choice, soldSeats = 0, firstClass, economy;
    char answer;

    
	while (soldSeats != 100) 
	{
        firstClass = 0;
        economy = 0;
        for (int i = 0; i < 30; i++) 
        {
            if (seats[i] == 0) // checking  if seats are available in first class or not
            {
                firstClass = 1;
            }
        }
        for (int i = 31; i < 100; i++)
        {
            if (seats[i] == 0) // checking  if seats are available in economy class or not
            {
                economy = 1;
            }
        }
        if (firstClass == 1 && economy == 1) // checking if both classes have available seats
        {
            system("cls");
            printf("Please type 1 for \"first class\"\n");
            printf("Please type 2 for \"economy\"\n");
            scanf_s("%d", &choice);
            while (choice != 1 && choice != 2)
            {
                printf("Wrong Choice!\nTry again\n");
                printf("Please type 1 for \"first class\"\n");
                printf("Please type 2 for \"economy\"\n");
                scanf_s("%d", &choice);
            }
            if (choice == 1)
            {
                printf("Select seat number (1-30): ");
                scanf_s("%d", &seatNumber);

                while (seatNumber < 1 || seatNumber > 30)
                {
                    printf("Wrong Choice!\nTry again\n");
                    printf("Select seat number (1-30): ");
                    scanf_s("%d", &seatNumber);
                }

                if (firstClassFun(seats, seatNumber) == 1) // checking if seat number is available or not in first class
                {
                    system("cls");
                    printf("\n\n********************************************************\n\n");
                    printf("\t\tBOARDING PASS\n");
                    printf("\t\tCLASS: first class\n");
                    printf("\t\tSEAT NUMBER: %d\n", seatNumber);
                    printf("\t\tTicket No: %c%d%c%d%c%d\n", 'A' + rand() % 26, rand() % 10, 'A' + rand() % 26, rand() % 10, 'A' + rand() % 26, rand() % 10);
                    printf("\t\tPrice: $350\n");
                    printf("\n\n********************************************************\n\n");
                }
                else
                {
                    system("cls");
                    printf("\n\n********************************************************\n\n");
                    printf("\tSorry! Seat number %d has already been sold.\n", seatNumber);
                    printf("\n\n********************************************************\n\n");
                }
            }
            else 
            {
                printf("Select seat number (31-100): ");
                scanf_s("%d", &seatNumber);

                while (seatNumber < 31 || seatNumber > 100)
                {
                    printf("Wrong choice!\nTry again\n");
                    printf("Select seat number (31-100): ");
                    scanf_s("%d", &seatNumber);
                }

                if (economyFunction(seats, seatNumber) == 1)
                {
                    system("cls");
                    printf("\n\n********************************************************\n\n");
                    printf("\t\tBoarding Pass\n");
                    printf("\t\tClass: Eeconomy Class\n");
                    printf("\t\tSeat Number: %d\n", seatNumber);
                    printf("\t\tTicket No: %c%d%c%d%c%d\n", 'A' + rand() % 26, rand() % 10, 'A' + rand() % 26, rand() % 10, 'A' + rand() % 26, rand() % 10);
                    printf("\t\tPrice: $200\n");
                    printf("\n\n********************************************************\n\n");
                }
                else
                {
                    printf("\n\n********************************************************\n\n");
                    printf("\tSorry! Seat number %d has already been sold.\n", seatNumber);
                    printf("\n\n********************************************************\n\n");
                }
            }
        }
        else if (economy == 1)
        {
            printf("All first class seats have been sold!\n ");
            printf("Is it acceptable to be placed in the economy section? (press \"y\")\n");
            scanf_s("%c", &answer, 1);

            if (answer == 'y' || answer == 'Y')
            {
                printf("Select seat number (31-100): ");
                scanf_s("%d", &seatNumber);

                while (seatNumber < 31 || seatNumber > 100)
                {
                    printf("Wrong choice!\nTry again\n");
                    printf("Select seat number (31-100): ");
                    scanf_s("%d", &seatNumber);
                }

                if (economyFunction(seats, seatNumber) == 1)
                {
                    system("cls");
                    printf("\n\n********************************************************\n\n");
                    printf("\t\tBoarding pass\n");
                    printf("\t\tClass: Economy Class\n");
                    printf("\t\tSeat Number: %d\n", seatNumber);
                    printf("\t\tTicket No: %c%d%c%d%c%d\n", 'A' + rand() % 26, rand() % 10, 'A' + rand() % 26, rand() % 10, 'A' + rand() % 26, rand() % 10);
                    printf("\t\tPrice: $200\n");
                    printf("\n\n********************************************************\n\n");
                }
                else
                {
                    system("cls");
                    printf("\n\n********************************************************\n\n");
                    printf("\tSorry! Seat number %d has already been sold.\n", seatNumber);
                    printf("\n\n********************************************************\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\n\n********************************************************\n\n");
                printf("\tNext flight leaves in 5 hours.\n\n");
                printf("\n\n********************************************************\n\n");
            }
        }
        else if (firstClass == 1)
        {
            printf("All economy class seats have been sold!\n ");
            printf("Is it acceptable to be placed in the fisrt class section? (press \"y\")\n");
            scanf_s(" %c ", &answer, 1);

            if (answer == 'y' || answer == 'Y')
            { 
                printf("Select seat number (1-30): ");
                scanf_s("%d", &seatNumber);

                while (seatNumber < 1 || seatNumber > 30)
                {
                    printf("Wrong Choice!\nTry again\n");
                    printf("Select seat number (1-30): ");
                    scanf_s("%d", &seatNumber);
                }

                if (firstClassFun(seats, seatNumber) == 1)
                {
                    system("cls");
                    printf("\n\n********************************************************\n\n");
                    printf("\t\tBOARDING PASS\n");
                    printf("\t\tCLASS: first class\n");
                    printf("\t\tSEAT NUMBER: %d\n", seatNumber);
                    printf("\t\tTicket No: %c%d%c%d%c%d\n", 'A' + rand() % 26, rand() % 10, 'A' + rand() % 26, rand() % 10, 'A' + rand() % 26, rand() % 10);
                    printf("\t\tPrice: $350\n");
                    printf("\n\n********************************************************\n\n");
                }
                else
                {
                    system("cls");
                    printf("\n\n********************************************************\n\n");
                    printf("\tSorry! Seat number %d has already been sold.\n", seatNumber);
                    printf("\n\n********************************************************\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\n\n********************************************************\n\n");
                printf("Next flight leaves in 5 hours.\n\n");
                printf("\n\n********************************************************\n\n");
            }
        }
        else
        {
        system("cls");
        printf("\n\n********************************************************\n\n");
        printf("\t\tSorry, there are no seats left.\n");        
        printf("\t\tNext flight leaves in 5 hours.");
        printf("\n\n********************************************************\n\n");
        soldSeats = 100;
        }
        Sleep(5000);
    }
    return 0;
}
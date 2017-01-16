/*
Name: Omar Rahman
Assignment: Assignment 02 - Cars
Date: 1/15/2017
*/

#include <stdlib.h>
#include <stdio.h>

#define CLS system("CLS");
#define PAUSE system("PAUSE");
#define FLUSH flush();

void displayMenu();
void flush();
int getSelection();

int main()
{

	int userSelection, price = 0;

	char firstTime = 'n', veteran = 'n', student = 'n', lastDay = 'n';

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 1:
			CLS;

			printf("What is the sticker price of the car you are buying? ");
			scanf_s("%d", &price);
			FLUSH;

			printf("Are you a first time buyer? (y/n) ");
			scanf_s("%c", &firstTime);
			FLUSH;

			printf("Are you a veteran? (y/n) ");
			scanf_s("%c", &veteran);
			FLUSH;

			printf("Are you a student? (y/n) ");
			scanf_s("%c", &student);
			FLUSH;

			printf("Is it the last day of the month? (y/n) ");
			scanf_s("%c", &lastDay);
			FLUSH;

			// Adjust price based on questions above
			if (lastDay == 'y')
			{
				price = price - (price * 0.05);
			}
			else if (student == 'y' && firstTime == 'y')
			{
				price = price - (price * 0.01) - 1700; // subtract all the other discounts and 1700 (700 + 500 + ADDITIONAL 500).
			}
			else if (firstTime == 'y')
			{
				price = price - 500;
			}
			else if (veteran == 'y')
			{
				price = price - (price * 0.01);
			}
			else if (student == 'y')
			{
				price = price - 700;
			}

			printf("Price of car: %d\n", price);

			PAUSE;

			break;

		case 2:
			CLS;

			printf("Total cars sold: \n");
			printf("Average car sold price: \n");
			printf("Total revenue: \n");

			PAUSE;

		default:

			break;
		}
	} while (userSelection != 3);

} // end main


void displayMenu()
{

	CLS;

	printf("================ Menu =================\n");
	printf("1. Enter a new sale\n");
	printf("2. Output\n");
	printf("3. Quit\n");
	printf("=======================================\n");

	printf("Enter your selection: ");

} // end displayMenu()

int getSelection()
{
	int result;

	displayMenu();
	scanf_s("%i", &result);

	FLUSH;

	return result;
} // end getSelection()

void flush()
{
	while (getchar() != '\n');
} // end flush
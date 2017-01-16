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

	int carSales[10] = { 0 };

	int userSelection, carSold = 0, price = 0, sum = 0;

	char firstTime = 'n', veteran = 'n', student = 'n', lastDay = 'n';

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 1:

			// Ask user for input, used for a sale
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
				price = price - (price * 0.05); // Last day of the month - %5
			}
			if (student == 'y' && firstTime == 'y')
			{
				price = price - (price * 0.01) - 1700; // subtract all the other discounts and 1700 (700 + 500 + ADDITIONAL 500).
			}
			if (firstTime == 'y')
			{
				price = price - 500; // First time -500
			}
			if (veteran == 'y')
			{
				price = price - (price * 0.01); // Vet - %1
			}
			if (student == 'y')
			{
				price = price - 700; // Student - %5
			}

			printf("Price of car: %d\n", price);

			carSold++; // Car is sold add one

			carSales[carSold] = price; // add the car price to carSales array

			PAUSE;

			break;

		case 2:
			CLS;

			printf("Total cars sold: %d\n", carSold); // Display cars sold

			for (int i = 0; i < 10; ++i)
			{
				sum += carSales[i];
			}

			printf("Average car sold price: %d\n", sum / carSold);
			printf("Total revenue: %d\n", sum);

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
/*
*	Name: Omar Rahman
*	Assignment: Assignment 03 - Menu-Function
*	Date: 1/22/2017
*	Purpose: Enter integers and modify them.
*/

#include <stdlib.h>
#include <stdio.h>

#define CLS system("CLS");
#define PAUSE system("PAUSE");
#define FLUSH flush();

void displayMenu();
void flush();
char getSelection();

int main()
{

	int userSelection;

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 'A':

			// Get ints

			CLS;

			printf("Test");

			PAUSE;

			break;

		case 'B':

			// Sum

			CLS;
			printf("Test");
			PAUSE;

			break;

		case 'C':

			// Product

			CLS;
			printf("Test");
			PAUSE;

			break;

		case 'D':

			// Avg

			CLS;
			printf("Test");
			PAUSE;

			break;

		case 'E':

			// Lowest

			CLS;
			printf("Test");
			PAUSE;

			break;

		case 'F':

			CLS;

			printf("Quitting...\n");

			break;

		default:

			printf("Invalid selection.\n");

			PAUSE;

			break;
		}
	} while (userSelection != 'F');

} // end main


void displayMenu()
{

	CLS;

	printf("================ Menu =================\n");
	printf("A. Get Three Integers\n");
	printf("B. Display The Sum\n");
	printf("C. Display The Product\n");
	printf("D. Display The Average\n");
	printf("E. Display The Lowest\n");
	printf("F. Quit\n");
	printf("=======================================\n");

	printf("Enter your selection: ");

} // end displayMenu()

void flush()
{
	while (getchar() != '\n');
} // end flush

char getSelection()
{
	char result;

	displayMenu();
	scanf_s("%c", &result);

	FLUSH;

	return toupper(result);
} // end getSelection()
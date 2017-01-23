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

int getSum();
int getProduct();
int getAvg();
int getLowest();

void displayMenu();
void flush();

char getSelection();

int main()
{

	int userSelection;
	int number1 = 0, number2 = 0, number3 = 0;

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 'A':

			CLS;

			printf("Enter integer 1: ");
			scanf_s("%i", &number1);
			FLUSH;

			printf("Enter integer 2: ");
			scanf_s("%i", &number2);
			FLUSH;

			printf("Enter integer 3: ");
			scanf_s("%i", &number3);
			FLUSH;

			PAUSE;

			break;

		case 'B':

			// Sum

			CLS;
			
			int sum = getSum(number1, number2, number3);

			printf("The sum is: %d\n", sum);

			PAUSE;

			break;

		case 'C':

			// Product

			CLS;
			
			int product = getProduct(number1, number2, number3);

			printf("The product is: %d\n", product);

			PAUSE;

			break;

		case 'D':

			// Avg

			CLS;

			int avg = getAvg(number1, number2, number3);

			printf("The average is: %d\n", avg);

			PAUSE;

			break;

		case 'E':

			// Lowest

			CLS;

			int lowest = getLowest(number1, number2, number3);
			
			printf("The lowest number is: %d\n", lowest);

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

int getSum(int num1, int num2, int num3)
{
	return num1 + num2 + num3;
} // end getSum()

int getProduct(int num1, int num2, int num3)
{
	return (num1 * num2 * num3);
} // end getProduct()

int getAvg(int num1, int num2, int num3)
{
	return (num1 + num2 + num3) / 3;
} // end getAvg()

int getLowest(int num1, int num2, int num3)
{
	int result;

	if (num1 < num2 && num1 < num3)
	{
		result = num1;
	}
	else if (num2 < num1 && num2 < num3)
	{
		result = num2;
	}
	else
	{
		result = num3;
	}

	return result;
} // end getLowest()
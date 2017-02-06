/*
*	
*/

#include <stdio.h>
#include <stdlib.h>

#define CLS system("cls");
#define PAUSE system("pause");

void displayMenu();

int getSelection();

int main()
{

	int userSelection;

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 1:
			CLS;



			PAUSE;

			break;

		case 2:
			CLS;

			PAUSE;

			break;

		case 3:
			CLS;

			PAUSE;

			break;

		case 4:
			CLS;

			PAUSE;

			break;

		case 5:
			CLS;

			PAUSE;

			break;

		default:

			PAUSE;

			break;
		}
	} while (userSelection != 5);

} // end main


void displayMenu()
{

	CLS;

	printf("================ Menu =================\n");
	printf("1. Display the average exam scores for a student\n");
	printf("2. Display the average exam scores for a student\n");
	printf("3. Display the class average\n");
	printf("4. Clear out the gradebook\n");
	printf("5. Quit\n");
	printf("=======================================\n");

	printf("Enter your selection: ");

} // end displayMenu()


int getSelection()
{
	int result;

	displayMenu();
	scanf_s("%i", &result);

	return result;
} // end getSelection()
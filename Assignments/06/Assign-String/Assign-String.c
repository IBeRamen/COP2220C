#include <stdio.h>
#include <stdlib.h>

#define PAUSE system("pause");
#define CLS system("cls");

void displayMenu();
void stringReverse(char*);

int getSelection();

int main()
{

	int userSelection;
	char s1[100];

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 1:
			CLS;

			printf("Enter a string (max 100 char): ");
			scanf_s("%s", s1);

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

void stringReverse(char* str)
{

}

void displayMenu()
{

	CLS;

	printf("================ Menu =================\n");
	printf("1. Example 1\n");
	printf("2. Example 2\n");
	printf("3. Example 3\n");
	printf("4. Example 4\n");
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
#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("PAUSE");
#define CLS system("CLS");

#define MAX 100000

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int day;
	int month;
	int year;
} DATE;

typedef struct {
	int id;
	char name[100];
	int age;
	float hourlyWage;
	float hoursWorked;
	float regularPay;
	float otPay;
	float totalPay;
	DATE payDate;
} PAYRECORD;

int main()
{

	PAYRECORD payroll[100000]; // allow the user to input 100,000 records

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

			printf("Saving file and exiting");

			break;

		default:

			printf("Invalid choice.");

			PAUSE;

			break;
		}
	} while (userSelection != 4);

	return 0;
}

void displayMenu()
{

	CLS;

	printf("================ Menu =================\n");
	printf("1. Search by date\n");
	printf("2. Enter new record\n");
	printf("3. Display total payroll\n");
	printf("4. Save & Quit\n");
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
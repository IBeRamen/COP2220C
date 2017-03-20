#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("PAUSE");
#define CLS system("CLS");

#define SIZE 100000

#include <stdio.h>
#include <stdlib.h>

void calcPay(float hourlyWage, float hoursWorked);
void displayMenu();
int getSelection();

typedef struct {
	int day;
	int month;
	int year;
} DATE;

typedef struct {
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

	static PAYRECORD payroll[SIZE] = { 0 }; // allow the user to input 100,000 records

	int userSelection;
	int searchDay, searchMonth, searchYear, id;
	int i = 0;

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 1:
			CLS;

			printf("Please enter the month: ");
			scanf("%i", &searchMonth);

			printf("Please enter the day: ");
			scanf("%i", &searchDay);

			printf("Please enter the year: ");
			scanf("%i", &searchYear);

			PAUSE;

			break;

		case 2:
			CLS;

			printf("Enter the student id: ");
			scanf("%i", &id);

			printf("Please enter the pay month: ");
			scanf("%i", &payroll[id].payDate.month);

			printf("Please enter the day: ");
			scanf("%i", &payroll[id].payDate.day);

			printf("Please enter the year: ");
			scanf("%i", &payroll[id].payDate.year);

			printf("Enter the name: ");
			scanf("%s", &payroll[id].name);

			printf("Enter the age: ");
			scanf("%d", &payroll[id].age);

			printf("Enter the hourly wage: ");
			scanf("%d", &payroll[id].hourlyWage);

			printf("Enter the hours worked: ");
			scanf("%d", &payroll[id].hoursWorked);

			calcPay(payroll[id].hourlyWage, payroll[id].hoursWorked);

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

void calcPay(float hourlyWage, float hoursWorked)
{
	float overtimeWorked, grossPay, overtimePay, regularPay;

	if (hoursWorked <= 40) {
		regularPay = hourlyWage * hoursWorked;
		overtimePay = 0.0;
		overtimeWorked = 0.0;
	}
	else {
		overtimeWorked = hoursWorked - 40;
		overtimePay = hourlyWage * 1.5 * overtimeWorked;
		regularPay = hourlyWage * (hoursWorked - overtimeWorked);
	}

	grossPay = regularPay + overtimePay;

	printf("Gross Pay: %.2f\n", grossPay);
	printf("Regular Pay: %.2f\n", regularPay);
	printf("Overtime Pay: %.2f\n", overtimePay);

} // end calcPay

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
	scanf("%i", &result);

	return result;
} // end getSelection()
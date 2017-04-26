/*
*	Assignment: Exam 4
*	Purpose: A bank management system in C.
*	Author: Omar Rahman
*/
#include "Header.h"

struct namerecord {
	char first[25];
	char last[25];
};

struct payrecord {
	int id;
	struct namerecord name;
	float hoursWorked;
	float hourlyRate;
	float regularWorked;
	float overtimeWorked;
	float gross;
	float tax;
	float netPay;
};

typedef struct payrecord payrecord;

int getRecords(payrecord payroll[], int max);
int getSelection();

double calcPayroll(payrecord payroll[], int n, double * tax);

void printAllRecords(payrecord payroll[], int n);
void printPayroll(double gross, double tax);
void getName(payrecord payroll[], int i);
void displayMenu();

int main()
{
	int userSelection;
	int i = 0, n = 0;

	double gross = 0, tax = 0;

	payrecord payroll[MAX];



	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 1:
			CLS;

			// Get the employee information from the user
			n = getRecords(payroll, MAX);

			PAUSE;

			break;

		case 2:
			CLS;

			printAllRecords(payroll, n);

			PAUSE;

			break;

		case 3:
			CLS;

			printPayroll(gross, tax);

			PAUSE;

			break;

		case 4:

			// Free memory
			free(payroll);

			break;

		default:

			PAUSE;

			break;
		}
	} while (userSelection != 4);

	return 0;
}

void displayMenu()
{

	CLS;

	printf("=========== PAYROLL PROGRAM ===========\n");
	printf("===========      Menu       ===========\n");
	printf("1. Add an employee\n");
	printf("2. Display ALL employees\n");
	printf("3. Print GROSS payroll\n");
	printf("4. Quit\n");
	printf("=======================================\n");

	printf("Enter your selection: ");

} // end displayMenu()


int getSelection()
{
	int result;

	displayMenu();
	scanf("%i", &result);
	fflush(stdin);

	return result;
} // end getSelection()

int getRecords(payrecord payroll[], int max)
{
	int i, j, n;
	float z;

	// Ask the user for the employee name
	void getName(payrecord payroll[], int i);

	// Loop array of structs
	for (i = 0; i < max; i++)
	{
		printf("ID Number: ");
		j = scanf("%d%*c", &n);

		// Error checking
		if (j == EOF)
			return i;

		payroll[i].id = n;

		getName(payroll, i);

		printf("Hours Worked: ");
		j = scanf("%f%*c", &z);
		payroll[i].hoursWorked = z;

		printf("Hourly Rate: ");
		j = scanf("%f%*c", &z);
		payroll[i].hourlyRate = z;

	} // end for loop

	return i;
}

void getName(payrecord payroll[], int i)
{
	printf("First Name: ");
	gets(payroll[i].name.first);

	printf("Last Name: ");
	gets(payroll[i].name.last);
}

double calcPayroll(payrecord payroll[], int n, double * tax)
{
	int i;

	double gross = 0;

	*tax = 0;

	// Loops through struct and calculates if an employee worked under 40 hours.
	// If an employee worked under 40 hours then calculate hoursWorked * hourlyWorked
	// Else get the amount of overtime worked and multiply hourly rate * 1.5
	// After calculating the gross income calculate the amount of tax to remove based
	// on income.

	// Tax removed from gross pay:
	// 10% if under 2000
	// 15% if under 5000
	// 25% if over 5000
	for (i = 0; i < n; i++)
	{
		if (payroll[i].hoursWorked <= 40)
		{
			payroll[i].overtimeWorked = 0;
			payroll[i].gross = payroll[i].hoursWorked * payroll[i].hourlyRate;
			payroll[i].regularWorked = payroll[i].gross;
		}
		else {
			payroll[i].regularWorked = 40 * payroll[i].hourlyRate;
			payroll[i].overtimeWorked = (payroll[i].hoursWorked - 40) * 1.5 * payroll[i].hourlyRate;
		}

		// Gross pay
		payroll[i].gross = payroll[i].regularWorked + payroll[i].overtimeWorked;

		if (payroll[i].gross <= 2000)
		{
			payroll[i].tax = payroll[i].gross * 0.1;
		}
		else if (payroll[i].gross <= 5000)
		{
			payroll[i].tax = payroll[i].gross * 0.15;
		}
		else if (payroll[i].gross > 5000)
		{
			payroll[i].tax = payroll[i].gross * 0.25;
		}

		gross += payroll[i].gross;

		*tax += payroll[i].tax;

		// Calculate the netPay by subtracting the grossPay with the tax taken out
		payroll[i].netPay = payroll[i].gross - payroll[i].tax;
	}

	return gross;
}

void printAllRecords(payrecord payroll[], int n)
{
	int i, x;

	float z;

	printf("===== Employee List =====");

	for (i = 0; i < n; i++)
	{
		printf("ID Number: %d\n", payroll[i].id);
		printf("Name: %s %s\n", payroll[i].name.first, payroll[i].name.last);
		printf("Hours Worked: %.2f\n", payroll[i].hoursWorked);
		printf("Overtime Worked: %.2f\n", payroll[i].overtimeWorked);
		printf("Hourly Rate: $%.2f\n", payroll[i].hourlyRate);
		printf("Gross Pay: $%.2f\n", payroll[i].gross);
		printf("Tax Paid: $%.2f\n", payroll[i].tax);
	}
}

void printPayroll(double gross, double tax)
{
	printf("Gross Pay: $%8.2f\n", gross);
	printf("Total Tax: $%8.2f\n", tax);
}

/*
*	Name: Omar Rahman
*	Assignment: Redo Payroll Assignment
*/

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause");
#define CLS system("cls");

#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void getData(struct payroll * p, int payRecSize);
void displayData(struct payroll * p, int payRecSize);
void search(struct payroll * p, int payRecSize);
int getSelection();

typedef struct {
	int day;
	int month;
	int year;
} DATE;

struct payroll {
	char name[100];
	int age;
	int id;
	float hrlyWage;
	float hrsWorked;
	float regPay;
	float otPay;
	float totalPay;
	DATE payDate;
};

int main()
{

	int userSelection, payRecSize;
	struct stdrec * j;

	// Ask the user for amount of students in class before showing menu
	printf("Enter the size of the payroll: ");
	scanf("%d%*c", &payRecSize);

	j = (struct payroll *)malloc(payRecSize *(sizeof(struct payroll)));

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{
		case 1:
			CLS;

			getData(j, payRecSize);

			PAUSE;

			break;

		case 2:
			CLS;

			displayData(j, payRecSize);

			PAUSE;

			break;

		case 3:
			CLS;

			search(j, payRecSize);

			PAUSE;

			break;

		case 4:
			CLS;

			printf("Quitting...");

			break;

		}
	} while (userSelection != 4);

	return 0;
}

void search(struct payroll * p, int payRecSize)
{
	int searchMonth, searchDay, searchYear;

	for (int i = 0; i < payRecSize; i++) {
		printf("Enter the month: ");
		scanf("%d%*c", &searchMonth);

		printf("Enter the day: ");
		scanf("%d%*c", &searchDay);

		printf("Enter the year: ");
		scanf("%d%*c", &searchYear);

		if (p->payDate.month == searchMonth
			&& p->payDate.day == searchDay
			&& p->payDate.year == searchYear)
		{
			CLS;
			printf("Match(s) found:\n\n");
			printf("Employee ID: %d", p->id);
			printf("\tEmployee Name: %s\n", p->name);
			printf("\tEmployee Age: %d\n", p->age);
			printf("\tHourly Wage: %.2f\n", p->hrlyWage);
			printf("\tHours Worked: %.2f\n", p->hrsWorked);
		}
		else
		{
			printf("No records found.\n");
		}

		printf("Press any key to go back to the main menu.\n");
		break;
	}
}

void getData(struct payroll * p, int payRecSize)
{	
	
	for (int i = 0; i < payRecSize; i++) {

		printf(
			"This will loop based on the size of the payroll.\n"
			"Example: If you specified size of 10. It will ask you\n"
			"to enter 10 records.\n\n"
		);

		printf("Employee ID: ");
		scanf("%d%*c", &p->id);

		printf("Employee Name: ");
		gets(p->name);

		printf("Employee Age: ");
		scanf("%d%*c", &p->age);

		printf("Hourly Wage: ");
		scanf("%f%*c", &p->hrlyWage);

		printf("Hours Worked: ");
		scanf("%f%*c", &p->hrsWorked);

		printf("Pay Month: ");
		scanf("%d%*c", &p->payDate.month);

		printf("Pay Day: ");
		scanf("%d%*c", &p->payDate.day);

		printf("Pay Year: ");
		scanf("%d%*c", &p->payDate.year);

		CLS;

		printf("Record added! Add the next record (if any).\n\n");
		printf("Employee ID: %d\n", p->id);
		printf("\tEmployee Name: %s\n", p->name);
		printf("\tEmployee Age: %d\n", p->age);
		printf("\tHourly Wage: %.2f\n", p->hrlyWage);
		printf("\tHours Worked: %.2f\n", p->hrsWorked);
		printf("\tPay Month: %d\n", p->payDate.month);
		printf("\tPay Day: %d\n", p->payDate.day);
		printf("\tPay Year: %d\n", p->payDate.year);

		PAUSE;

		CLS;

		p++;

	}
}

void displayData(struct payroll * p, int payRecSize)
{
	float regPay, otPay, otWorked, totalPay;
	for (int i = 0; i < payRecSize; i++)
	{
		// Calculate pay
		if (p->hrsWorked <= 40)
		{
			p->regPay = p->hrlyWage * p->hrsWorked;
			p->otPay = 0.0;
		}
		else {
			otWorked = p->hrsWorked - 40;
			p->regPay = p->hrlyWage * (p->hrsWorked - otWorked);
			p->otPay = (p->hrlyWage * 1.5) * otWorked;
		}
		p->totalPay = p->regPay + p->otPay;

		printf("ID: %d\n", p->id);
		printf("\tRegular Pay: %.2f\n", p->regPay);
		printf("\tOvertime Pay: %.2f\n", p->otPay);
		printf("\tTotal Pay: %.2f\n", p->totalPay);

		p++;
	}
}


void displayMenu()
{

	CLS;

	printf("Payroll Record\n\n");
	printf("================ Menu =================\n");
	printf("1. Add a payroll record\n");
	printf("2. Display total payroll\n");
	printf("3. Search\n");
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
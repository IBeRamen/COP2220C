/*
*	Name: Omar Rahman
*	Assignment: Dynamic Memory Array
*/

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("pause");
#define CLS system("cls");

void getData(struct stdrec * p, int numOfStudents);
void displayAverage(struct stdrec * p, int numOfStudents);
void displayData(struct stdrec * p, int numOfStudents);
void displayMenu();
void displayTotalAvg(struct stdrec * p, int numOfStudents);
int getSelection();

#include <stdlib.h>
#include <stdio.h>

struct stdrec {
	char name[20];
	int id;
	float exam1;
	float exam2;
	float exam3;
	float exam4;
};

int main()
{

	int userSelection, numOfStudents;
	struct stdrec * j;

	// Ask the user for amount of students in class before showing menu
	printf("Enter the number of students: ");
	scanf("%d%*c", &numOfStudents);

	j = (struct stdrec *)malloc(numOfStudents *(sizeof(struct stdrec)));

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 1:
			CLS;

			if (j)
			{
				getData(j, numOfStudents);
			}
			else
			{
				printf("Out of memory\n");
			}

			PAUSE;

			break;

		case 2:
			CLS;

			displayData(j, numOfStudents);

			PAUSE;

			break;

		case 3:
			CLS;

			displayAverage(j, numOfStudents);

			PAUSE;

			break;

		case 4:
			CLS;

			displayTotalAvg(j, numOfStudents);

			PAUSE;

			break;

		case 5:
			CLS;

			printf("Quitting...");

			break;

		default:

			PAUSE;

			break;
		}
	} while (userSelection != 5);
		
}

void getData(struct stdrec * p, int numOfStudents)
{

	for (int i = 0; i < numOfStudents; i++) {

		printf("Student ID: ");
		scanf("%d%*c", &p->id);

		printf("Student name: ");
		gets(p->name);

		printf("Exam 1 score: ");
		scanf("%f%*c", &p->exam1);

		printf("Exam 2 score: ");
		scanf("%f%*c", &p->exam2);

		printf("Exam 3 score: ");
		scanf("%f%*c", &p->exam3);

		printf("Exam 4 score: ");
		scanf("%f%*c", &p->exam4);

		p++;

	}
}

void displayAverage(struct stdrec * p, int numOfStudents)
{
	float avg;

	for (int i = 0; i < numOfStudents; i++)
	{
		avg = (p->exam1 + p->exam2 + p->exam3 + p->exam4) / 4;
		printf("Student Name: %s\n", p->name);
		printf("\tID: %d\n", p->id);
		printf("\tAverage: %.2f\n", avg);

		p++;
	}
}

void displayData(struct stdrec * p, int numOfStudents)
{

	for (int i = 0; i < numOfStudents; i++)
	{
		printf("Student Name: %s\n", p->name);
		printf("\tID: %d\n", p->id);
		printf("\tExam 1: %.2f\n", p->exam1);
		printf("\tExam 2: %.2f\n", p->exam2);
		printf("\tExam 3: %.2f\n", p->exam3);
		printf("\tExam 4: %.2f\n", p->exam4);

		p++;
	}
}

void displayTotalAvg(struct stdrec * p, int numOfStudents)
{

	float avg = 0.0;

	for (int i = 0; i < numOfStudents; i++)
	{
		avg = (p->exam1 + p->exam2 + p->exam3 + p->exam4) / 4;
		printf("Class Average: %.2f\n", avg);

		p++;
	}
}

void displayMenu()
{

	CLS;

	printf("Student Records\n\n");
	printf("================ Menu =================\n");
	printf("1. Add a student\n");
	printf("2. Display Students Records\n");
	printf("3. Display Students Average\n");
	printf("4. Display Class Average\n");
	printf("5. Quit\n");
	printf("=======================================\n");

	printf("Enter your selection: ");

} // end displayMenu()


int getSelection()
{
	int result;

	displayMenu();
	scanf_s("%i", &result);
	fflush(stdin);

	return result;
} // end getSelection()

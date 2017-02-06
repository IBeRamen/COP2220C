/*
*	Name: Omar Rahman
*	Assignment: Assignment 05 - IO-Processing
*	Date: 2/5/2017
*	Purpose: IO and console gradebook.
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

#define CLS system("cls");
#define PAUSE system("pause");
#define FLUSH flush();
#define SIZE 10

void displayMenu();
void flush();

int getSelection();

int main()
{

	int userSelection;

	static int students[SIZE][4];

	// Create the binary file or open if not made

	FILE *fp;

	fp = fopen("gradebookbinary.txt", "wb");

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 1:

			// Get the grades

			CLS;

			int studentID, exam1, exam2, exam3, exam4;

			printf("Enter student ID: ");
			scanf_s("%i", &studentID);
			FLUSH;

			printf("Enter exam #1 score: ");
			scanf_s("%i", &exam1);
			students[studentID][1] = exam1;

			printf("Enter exam #2 score: ");
			scanf_s("%i", &exam2);
			students[studentID][2] = exam2;

			printf("Enter exam #3 score: ");
			scanf_s("%i", &exam3);
			students[studentID][3] = exam3;

			printf("Enter exam #4 score: ");
			scanf_s("%i", &exam4);
			students[studentID][4] = exam4;

			PAUSE;

			break;

		case 2:

			// Get the average for a student

			CLS;

			float sum = 0.0;

			printf("Find the average for student #: ");
			scanf_s("%i", &studentID);

			for (int i = 0; i <= 4; i++)
			{
				sum += students[studentID][i];
			}

			printf("The average for student #%i is %.2f.\n", studentID, sum / 4);

			PAUSE;

			break;

		case 3:

			// Get the class average for a specific exam

			CLS;

			int exam = 0;
			sum = 0;

			printf("Find the average for exam #: ");
			scanf_s("%i", &exam);

			for (int i = 0; i < SIZE; i++)
			{
				sum += students[i][exam];
			}

			printf("The average for exam #%i is %.2f.\n", exam, sum / SIZE);

			PAUSE;

			break;

		case 4:

			// Get the class average

			CLS;

			sum = 0;

			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					sum += students[i][j];
				}
			}

			printf("The class average is %.2f.\n", sum / SIZE);

			PAUSE;

			break;

		case 5:

			// Save students array to gradebook.txt

			CLS;

			fp = fopen("gradebook.txt", "w");

			for (int i = 0; i <= SIZE; i++)
			{
				for (int j = 0; j <= 4; j++)
				{
					fprintf(fp, "students[%i][%i] = %i\n", i, j, students[i][j]);
				}
			}

			fclose(fp);

			printf("Saved as gradebook.txt....\n");

			PAUSE;

			break;

		case 6:

			// Remake gradebook.txt and set array to 0

			CLS;

			fp = fopen("gradebook.txt", "w+");

			fclose(fp);

			static int students[SIZE][4] = { 0 };

			PAUSE;

			break;

		case 7:
			CLS;

			// Couldn't get this to work write with 2D arrays...

			fp = fopen("gradebookbinary.txt", "wb");

			for (int i = 0; i <= SIZE; i++)
			{
				fwrite(&students[i], sizeof(students[i][0]), SIZE, fp);
			}

			fclose(fp);


			printf("Quitting...");

			break;

		default:

			PAUSE;

			break;
		}
	} while (userSelection != 7);

	return 0;

} // end main

void displayMenu()
{

	CLS;

	printf("================ Menu =================\n");
	printf("1. Enter exam scores\n");
	printf("2. Display the average exam scores for a student\n");
	printf("3. Display the average exam scores by exam\n");
	printf("4. Display the class average\n");
	printf("5. Output to gradebook.txt\n");
	printf("6. Clear out the gradebook\n");
	printf("7. Quit\n");
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
} // end flush();
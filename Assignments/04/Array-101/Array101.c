/*
*	Name: Omar Rahman
*	Assignment: Assignment 04 - Array-101
*	Date: 1/26/2017
*	Purpose: Keeps track of a season of games for your favorite sports team.
*/

#include <stdlib.h>
#include <stdio.h>

#define PAUSE system("pause");
#define CLS system("cls");
#define FLUSH flush();
#define results 1000
#define col 1

void flush();

void displayMenu();

char getSelection();

int main()
{

	int resultsHome[results][col];
	int resultsEnemy[results][col];
	int resultsCompare[results][col];
	int resultsWon[results][col];

	int userSelection, i, j;

	int games = 0, wins = 0, losses = 0, ties = 0;

	do
	{
		userSelection = getSelection();

		switch (userSelection)
		{

		case 'A':
			CLS;
			
			for (i = 0; i < results; i++)
			{
				for (j = 0; j < col; j++)
				{
					printf("Game #%d, Home Score #%d: ", i + 1, j + 1);
					scanf_s("%d", &resultsHome[i][j]);
					FLUSH;
				}
			}

			for (i = 0; i < results; i++)
			{
				for (j = 0; j < col; j++)
				{
					printf("Game #%d, Enemy Score #%d: ", i + 1, j + 1);
					scanf_s("%d", &resultsEnemy[i][j]);
					FLUSH;
				}
			}

			PAUSE;

			break;

		case 'B':
			CLS;

			// reset wins, losses and ties if B is selected again
			wins = 0, losses = 0, ties = 0;

			for (i = 0; i < results; i++)
			{
				for (j = 0; j < col; j++)
				{
					if (resultsHome[i][j] > resultsEnemy[i][j])
					{
						wins++;
					}
					else if (resultsHome[i][j] < resultsEnemy[i][j])
					{
						losses++;
					}
					else
					{
						ties++;
					}
				}
			}

			printf("Home team has won %d times.\n", wins);
			printf("Home team has lost %d times.\n", losses);
			printf("Home team has tied %d times.\n", ties);

			PAUSE;

			break;

		case 'C':
			CLS;

			for (i = 0; i < results; i++)
			{
				for (j = 0; j < col; j++)
				{
					if (resultsHome[i][j] > resultsEnemy[i][j])
					{
						printf("Game #%d, Winning score: %d\n", i + 1, resultsHome[i][j]);
					}
				}
			}

			PAUSE;

			break;

		case 'D':
			CLS;

			for (i = 0; i < results; i++)
			{
				for (j = 0; j < col; j++)
				{
					printf("Game #%d, Home Score = %d\n", i + 1, resultsHome[i][j]);
					printf("Game #%d, Enemy Score = %d\n", i + 1, resultsEnemy[i][j]);
				}
			}

			PAUSE;

			break;

		case 'Q':
			CLS;

			printf("Quitting...");

			break;

		default:

			PAUSE;

			break;
		}
	} while (userSelection != 'Q');

} // end main


void displayMenu()
{

	CLS;

	printf("================ Menu =================\n");
	printf("A. Enter game results\n");
	printf("B. Current Record\n");
	printf("C. Display all results from all games won\n");
	printf("D. Display all results\n");
	printf("Q. Quit\n");
	printf("=======================================\n");

	printf("Enter your selection: ");

} // end displayMenu()


char getSelection()
{
	char result;

	displayMenu();
	scanf_s("%c", &result);
	
	FLUSH;

	return toupper(result);
} // end getSelection()

void flush()
{
	while (getchar() != '\n');
} // end flush();
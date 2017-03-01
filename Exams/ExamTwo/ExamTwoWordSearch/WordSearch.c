/*
*	Assignment: Exam Two Word Search
*	Date: 2/28/2017
*	Author: Omar Rahman
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PAUSE system("pause");
#define CLS system("CLS");
#define NUMBEROFWORDS 18
#define MAXSIZE 10

int main()
{
	srand((unsigned)time(NULL));

	const char *puzzle[35][70] = { "" };
	char userInput[MAXSIZE] = { "" };

	int maxwords = 0;

	do {
		printf("How many words would you like to enter? (Max 18): ");
		scanf("%i", &maxwords);
	} while (maxwords > 18);

	for (int i = 0; i < maxwords; i++)
	{
		printf("Enter a word (Up to 10 letters): ");
		scanf("%s", userInput);
	}

	strncpy(puzzle, userInput, sizeof(userInput) -1);

	for (int i = 0; i < sizeof puzzle / sizeof *puzzle; i++)
	{
		printf("\n%s", puzzle[i]);
	}

	/*
	void reverseString(char *str)
{
	for (int i = strlen(str); i >= 0; i--)
	{
		printf("%c", str[i]);
	}
}

void outputLength(char *str)
{
	printf("%i", strlen(str));
}

void outputVertical(char *str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		printf("\n%c", str[i]);
	}
}

void outputTriangle(char *str)
{
	for (int i = strlen(str); i >= 0; i--)
	{
		printf("\n");
		for (int j = 0; j < i; j++)
		{
			printf("%c", str[j]);
		}
	}
}
	*/


	PAUSE;

	return 0;
}
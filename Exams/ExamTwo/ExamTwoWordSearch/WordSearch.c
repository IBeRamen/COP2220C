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

	char puzzle[35][70] = { "" };
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
		printf("%s", puzzle[i]);
	}


	PAUSE;

	return 0;
}
/*
*	Name: Omar Rahman
*	Date: 2/19/2017
*	Assignment: Assign-String - String manipulation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAUSE system("pause");
#define CLS system("cls");
#define FLUSH flush();

void outputString(char *str);
void reverseString(char *str);
void outputLength(char *str);
void outputVertical(char *str);
void outputTriangle(char *str);
void flush();

int main()
{
	char replay;
	char* userString[100];

	do
	{
		CLS;

		printf("Enter a string (up to 100 characters): ");
		fgets(userString, 100, stdin);
		fflush(stdin);
		//scanf_s("%99s", userString, 100);

		printf("The string: ");
		outputString(userString);

		printf("Reveresed: ");
		reverseString(userString);

		printf("\n\nLength: ");
		outputLength(userString);

		printf("\n\nVertical: ");
		outputVertical(userString);

		printf("Triangle: ");
		outputTriangle(userString);

		printf("Play again? (Y/N) ");
		scanf_s(" %c", &replay);
		FLUSH;
	} while (replay == 'y' || replay == 'Y');


	return 0;
} // end main

void outputString(char *str)
{
	printf("%s\n", str);
}

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

void flush()
{
	while (getchar() != '\n');
} // end flush();
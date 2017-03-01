#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int getInput(char *buffer, size_t buflen);
static int search_direction(char array[32][70], char *string, int length, int X, int Y, int dx, int dy);
static int search_from(char array[32][70], char *string, int length, int X, int Y);

int main(void)
{
	// Declare variables
	int X = 0, Y = 0, length = 0, maxwords = 0;
	char array[32][70] = { "" }, string[10] = { "" }, userInput[10] = { "" };

	printf("Exam Two Word Search\n\n");

	// Open Words Text
	FILE *wsch = fopen("words.txt", "r");

	if (!wsch)
	{
		printf("Error! File did not open.\n");
		return 1;
	}

	for (Y = 0; Y < 32; Y++)
	{
		for (X = 0; X < 70; X++)
		{
			fscanf(wsch, " %c", &array[Y][X]);
			array[Y][X] = toupper(array[Y][X]);
		}
	}
	
	fclose(wsch);

	printf("   ");
	printf("\n______________________________________\n");
	for (Y = 0; Y < 32; Y++)
	{
		printf("%-2d|", Y);
		for (X = 0; X < 70; X++)
			printf("%c ", array[Y][X]);
		printf("\n");
	}

	while ((length = getInput(string, sizeof(string))) != EOF)
	{
		printf("Searching for: [%s]\n", string);

		int count = 0;
		for (Y = 0; Y < 32; Y++)
		{
			for (X = 0; X < 70; X++)
			{
				if (array[Y][X] == (string[0]) && search_from(array, string, length, X, Y))
					count++;
			}
		}

		printf("Found %s %d times\n", string, count);
	}

	printf("\n");
	return 0;
}

// Gets user input
static int getInput(char *buffer, size_t buflen)
{
	printf("\nPlease enter the word to be searched: ");
	if (fgets(buffer, buflen, stdin) == 0)
		return EOF;
	size_t length = strlen(buffer);
	if (buffer[length - 1] == '\n')
		buffer[--length] = '\0';
	if (length == 0)
		return EOF;
	for (size_t i = 0; i < length; i++)
		buffer[i] = toupper(buffer[i]);
	return length;
}

static int search_from(char array[32][70], char *string, int length, int X, int Y)
{
	struct yx { int dy; int dx; } directions[] =
	{
		{ +1, 0 },{ -1, 0 },{ +1, +1 },{ -1, +1 },
		{ 0, +1 },{ 0, -1 },{ -1, -1 },{ +1, -1 },
	};
	enum { num_directions = sizeof(directions) / sizeof(directions[0]) };
	int count = 0;

	for (int i = 0; i < num_directions; i++)
	{
		if (search_direction(array, string, length, X, Y, directions[i].dx, directions[i].dy))
			count++;
	}
	return count;
}

static int search_direction(char array[32][70], char *string, int length, int X, int Y, int dx, int dy)
{
	for (int i = 1; i < length; i++)
	{
		int x = X + i * dx;
		int y = Y + i * dy;
		if (x < 0 || x >= 32 || y < 0 || y >= 70)
			return 0;
		if (array[y][x] != string[i])
			return 0;
	}

	printf("Found word %s starting at (%d,%d) to (%d,%d)\n",
		string, Y, X, Y + (length - 1) * dy, X + (length - 1) * dx);
	char *pad = "";
	for (int i = 0; i < length; i++)
	{
		int x = X + i * dx;
		int y = Y + i * dy;
		printf("%s%c (%d,%d)", pad, array[y][x], y, x);
		pad = ", ";
	}
	putchar('\n');

	return 1;
}
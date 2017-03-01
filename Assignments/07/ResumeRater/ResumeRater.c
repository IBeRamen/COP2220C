/*
*	Assignment: Resume Ratter
*	Author: Omar Rahman
*	Date: 2/12/2017
*/

#define _CRT_SECURE_NO_WARNINGS
#define PAUSE system("PAUSE")

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char convertString(FILE *fp);

int main() {

	FILE* resume;
	FILE* keywords;

	char keyword[50] = { "" };
	char scannedWord[50];
	int count = 0;

	resume = fopen("resume.txt", "r");

	// Check for errors
	if (!resume) {
		printf("Error! Cannot open file.\n");
		return 1;
	}

	printf("Enter keyword to find in resume.txt: ");
	scanf("%s", keyword);

	while (1) {

		fscanf(resume, " ,");

		if (fscanf(resume, " %20[^, \t\n]", scannedWord) == 1) {

			if (!strcmp(scannedWord, keyword)) {
				count++;
			}

		}
		// Once reached the end of the file, break loop
		if (feof(resume))
		{
			break;
		}
	}

	printf("Found %i times.\n", count);

	fclose(resume);

	PAUSE;

	return 0;
}

const char convertString(FILE *fp)
{
	char* buffer = 0;
	long length;
	FILE *f = fopen(fp, "rb");

	if (f)
	{
		fseek(f, 0, SEEK_END);
		length = ftell(f);
		fseek(f, 0, SEEK_SET);
		buffer = malloc(length);
		if (buffer)
		{
			fread(buffer, 1, length, f);
		}
		fclose(f);
	}

	return buffer;
}
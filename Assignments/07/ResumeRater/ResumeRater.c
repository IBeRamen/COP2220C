#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PAUSE system("pause");
#define CLS system("cls");

const char convertString(FILE *fp);

int main() {

	char resume = convertString("resume.txt");
	char keywords = convertString("keywords.txt");

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
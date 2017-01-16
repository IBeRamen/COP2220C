/*
	Name: Omar Rahman
	Assignment: Assignment 01 - Loop
	Date: 1/15/2017
*/

#include <stdlib.h>
#include <stdio.h>

void showOutput();

int main() {

	showOutput();

	system("PAUSE");

	return 0;
}

void showOutput()
{
	// Ugly, but it works!
	printf("%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c", "1. x equals 10.", putchar(10), "2. x equals 9.", 
		putchar(10), "3. x equals 8.", putchar(10), "4. x equals 7", putchar(10), "5. x equals 6.",
		putchar(10), "6. x equals 5.", putchar(10), "7. x equals 4.", putchar(10), "8. x equals 3.", 
		putchar(10), "9. x equals 2.", putchar(10), "10. x equals 1.");
}
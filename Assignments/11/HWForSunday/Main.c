/*
*	Name: Omar Rahman
*	Assignment: Homework for Sunday
*	Description: Adding Saving/Loading from a bin file and freeing memory
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define PAUSE system("pause")
#define CLS system("cls");

typedef struct {
	int age;
	int weight;
	int height;
} STATS;

STATS *makeArrayOfPointers(int size);
void loadArray(STATS **array, int *c);
void displayArray(STATS **array, int c);

int main() {
	STATS** array;

	FILE *fp;

	int count = 0;
	int size = 500;
	
	array = makeArrayOfPointers(size);

	// Load the array
	loadArray(array, &count);
	printf("Address of the array: %p\n", array);

	// Display the array
	displayArray(array, count);
	printf("Age is %i.\n", array[0]->age);

	// Save the array
	fp = fopen("save.bin", "wb");

	fwrite(array, 1, size, fp);

	fclose(fp);

	// Free memory
	free(array);

	printf("Array saved in save.bin!");

	PAUSE;

	return 0;
}

void displayArray(STATS **array, int c) {
	int i;

	for (i = 0; i < c; i++) {
		printf("Record[%i] Age is %i.\t  Weight is %i.\t Height is %i.\n", i, array[i]->age, array[i]->weight, array[i]->height);
	}

	PAUSE;
}

void loadArray(STATS **array, int *c) {
	int value;
	int counter = *c;

	for (*c; *c < (counter + 4); *c = *c + 1) {
		array[*c] = calloc(1, sizeof(STATS));
		printf("Enter age: ");
		scanf("%i", &value);
		array[*c]->age = value;

		printf("Enter weight: ");
		scanf("%i", &value);
		array[*c]->weight = value;

		printf("Enter height: ");
		scanf("%i", &value);
		array[*c]->height = value;
	}

	PAUSE;
}

STATS *makeArrayOfPointers(int size) {
	STATS *result;

	result = malloc(sizeof(STATS*) * size);

	return result;
}

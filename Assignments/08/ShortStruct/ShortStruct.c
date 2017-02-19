/*
*	Name: Omar Rahman
*	Date: 2/19/2017
*	Assignment: Short-Struct, a basic program to understand structs.
*/

#include <stdio.h>
#include <stdlib.h>

void output(struct Person *p1, struct Person *p2, struct Person *p3);
void setPerson(struct Person *p1, struct Person *p2, struct Person *p3);

typedef struct DATE {
	int month;
	int day;
	int year;
} DATE;

struct Person
{
	char name[32];
	DATE birthdate;
	char gender[5];
	float salary;
} person1, person2, person3;

int main() {

	setPerson(&person1, &person2, &person3);
	output(&person1, &person2, &person3);

	system("PAUSE");

	return 0;
}

void setPerson(struct Person *p1, struct Person *p2, struct Person *p3)
{

	strcpy(person1.name, "Woody Parker");
	person1.birthdate.month = 12;
	person1.birthdate.day = 18;
	person1.birthdate.year = 1995;
	strcpy(person1.gender, "Male");
	person1.salary = 40000.00;

	strcpy(person2.name, "Mary Jane");
	person2.birthdate.month = 4;
	person2.birthdate.day = 13;
	person2.birthdate.year = 1992;
	strcpy(person2.gender, "Female");
	person2.salary = 60000.00;

	strcpy(person3.name, "Steve James");
	person3.birthdate.month = 8;
	person3.birthdate.day = 10;
	person3.birthdate.year = 1997;
	strcpy(person3.gender, "Male");
	person3.salary = 100000.00;
}

void output(struct Person *p1, struct Person *p2, struct Person *p3)
{
	printf(
		"Name: %s\n"
		"Birthday: %i/%i/%i\n"
		"Gender: %s\n"
		"Salary: %.2f\n\n",
		p1->name,
		p1->birthdate.month,
		p1->birthdate.day,
		p1->birthdate.year,
		p1->gender,
		p1->salary
	);

	printf(
		"Name: %s\n"
		"Birthday: %i/%i/%i\n"
		"Gender: %s\n"
		"Salary: %.2f\n\n",
		p2->name,
		p2->birthdate.month,
		p2->birthdate.day,
		p2->birthdate.year,
		p2->gender,
		p2->salary
	);

	printf(
		"Name: %s\n"
		"Birthday: %i/%i/%i\n"
		"Gender: %s\n"
		"Salary: %.2f\n",
		p3->name,
		p3->birthdate.month,
		p3->birthdate.day,
		p3->birthdate.year,
		p3->gender,
		p3->salary
	);
}
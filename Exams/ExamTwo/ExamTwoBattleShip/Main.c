/*
*	Assignment: Exam Two Battleship
*	Author:  Jacob Butler
*	Date: 2/28/2017
*/

#include "BattleshipHeader.h"

int main(void)
{
	static int choice, round;
	static int board[8][8][4], leaderScores[10];
	static char leaderNames[10][20];
	FILE *leaders = fopen("leaders.txt", "r+");
	for (int i = 0; i < 10; i++)
		fscanf(leaders, "%s %i", leaderNames[i], &leaderScores[i]);
	rewind(leaders);
	srand(time(NULL));

	// place ships randomly
	fill(board);

	// menu
	do
	{
		menu(&choice);

		switch (choice)
		{
		case 1:
			turn(&round, board, leaders, leaderNames, leaderScores);
			break;
		case 2:
			leader(leaders);
			break;
		}

	} while (choice != 3);

	// THE END!
	fclose(leaders);
	return 0;
}
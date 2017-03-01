/*
*	Assignment: Exam Two Battleship
*	Author:  Jacob Butler
*	Date: 2/28/2017
*/

#include "BattleshipHeader.h"


void menu(int *choice)
{
	clr();

	printf("\nBATTLESHIP!"
		"\n\n 1. New Game"
		"\n 2. Leader Board"
		"\n 3. Quit"
		"\n\nSelection: ");
	scanf("%i", choice);
}


void turn(int *round, int board[][8][4], FILE *leaders, char leaderNames[][20], int *leaderScores)
{
	static int guess[2];
	static char winner[20];
	static int newLeader = 1;

	do
	{
		clr();
		getchar();
		printf("Player %i ready?", *round % 2 + 1);
		puts("\nPress ENTER...");
		getchar();
		clr();

		printf("Player %i", *round % 2 + 1);
		printf("\n1: cruiser, 2: aircraft carrier,"
			"\n3: battleship, 4: submarine, 5: destroyer");
		printf("\nx: spot fired on, h: hit a ship, -: empty space");
		draw(round, board);

		printf("\n\nFire on\n"
			"\n  row: ");
		scanf("%i", &guess[0]);
		printf("  column: ");
		scanf("%i", &guess[1]);

		while (checkFire(round, guess, board))
			;

		(*round)++;
	} while (notOver(board));

	(*round)--;

	clr();
	getchar();
	printf("You're a winner!"
		"\n\nWhat's your name, winner: ");
	scanf("%20[^\n]", winner);
	printf("\nENTER to continue...");
	getchar();

	for (int i = 0; i < 10; i++)
	{
		fscanf(leaders, "%s %i", leaderNames[i], &leaderScores[i]);
	}
	rewind(leaders);

	for (int i = 0; i < 10; i++) {
		if (strcmp(leaderNames[i], winner)) {
			leaderScores[i]++;
			newLeader = 0;
		}
	}

	if (newLeader)
		for (int i = 0; i < 10; i++)
			if (leaderNames[i][0] == 0) {
				memcpy(leaderNames[i], winner, sizeof(winner));
				leaderScores[i]++;
			}

	for (int i = 0; i < 10; i++)
	{
		fprintf(leaders, "%s %i\n", leaderNames[i], leaderScores[i]);
	}
	rewind(leaders);
}

void leader(FILE *leaders)
{
	int c;
	clr();

	printf("LEADER BOARD!\n\n");
	while ((c = getc(leaders)) != EOF)
	{
		putchar(c);
	}

	getchar();
	printf("\nENTER: main menu...");
	getchar();
}

/* the way board is set up:
*
* board[x][y][properties]:
*
* properties == 0 =  unused (0)
*                    used   (1)
*
*               1 = player1 (0)
*                   player2 (1)
*
*               2 = cruiser (1)
*                   airCarr (2)
*                   battles (3)
*                   submari (4)
*                   destroy (5)
*
*               3 = unhit   (0)
*                   hit     (1)
*/

int checkFire(int *round, int *guess, int board[][8][4])
{
	int x = guess[0], y = guess[1], player = *round % 2;

	while (board[x][y][1] == player
		&& board[x][y][0] == 1) {
		printf("\nYe can't fire on ye own ship!\n"
			"\n   row: ");
		scanf("%i", guess);
		printf("   column: ");
		scanf("%i", (guess + 1));
		return 1;
	}

	if (x > 7 || y > 7 ||
		x < 0 || y < 0) {
		printf("\nNot on the board!\n");
		return 1;
	}

	board[x][y][3] = 1;

	return 0;
}


int notOver(int board[][8][4])
{
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			for (int player = 0; player < 2; player++)
			{
				if (board[x][y][1] == player
					&& board[x][y][0] == 1
					&& board[x][y][3] == 0)
					return 1;
			}
		}
	}
	return 0;
}

void draw(int *round, int board[][8][4])
{
	if (*round % 2 + 1 == 1) {
		printf("\n\n");
		for (int i = 0; i < 8; i++)
		{
			putchar('\n');
			printf("%i)  ", i % 8);
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j][1] == 0 && board[i][j][3] == 0) {
					if (board[i][j][2] == 0)
						putchar('-');
					else
						printf("%i", board[i][j][2]);
				}
				else if (board[i][j][3] == 1
					&& board[i][j][1] != *round % 2
					&& board[i][j][0] == 1) {
					putchar('h');
				}
				else if (board[i][j][3] == 1) {
					putchar('x');
				}
				else {
					putchar('-');
				}
				printf("  ");
			}
			putchar('\n');
		}
	}
	else {
		printf("\n\n");
		for (int i = 0; i < 8; i++)
		{
			putchar('\n');
			printf("%i)  ", i % 8);
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j][1] == 1 && board[i][j][3] == 0) {
					if (board[i][j][2] == 0)
						putchar('-');
					else
						printf("%i", board[i][j][2]);
				}
				else if (board[i][j][3] == 1
					&& board[i][j][1] != *round % 2
					&& board[i][j][0] == 1) {
					putchar('h');
				}
				else if (board[i][j][3] == 1) {
					putchar('x');
				}
				else {
					putchar('-');
				}

				printf("  ");
			}
			putchar('\n');
		}
	}
	printf("\n   (0)(1)(2)(3)(4)(5)(6)(7)\n");
}

void fill(int board[][8][4])
{
	for (int player = 0; player < 2; player++)
	{
		placeCruiser(player, board);
		placeAC(player, board);
		placeBS(player, board);
		placeSB(player, board);
		placeDS(player, board);
	}
}


int inUse(int *square, int board[][8][4])
{
	if (*square > 7 || *square < 0)
		return 1;

	if (*(square + 1) > 7 || *(square + 1) < 0)
		return 1;

	if (board[*square][*(square + 1)][0] == 1)
		return 1;
	else
		return 0;
}


void placeCruiser(int player, int board[][8][4])
{
	static int cruiser[2][2];

	do
	{
		cruiser[0][0] = rand() % 8;
		cruiser[0][1] = rand() % 8;

		switch (player)
		{
		case 0:
			cruiser[1][0] = cruiser[0][0] + 1;
			cruiser[1][1] = cruiser[0][1];
			break;
		case 1:
			cruiser[1][0] = cruiser[0][0];
			cruiser[1][1] = cruiser[0][1] + 1;
			break;
		}
	} while (inUse(cruiser[0], board)
		|| inUse(cruiser[1], board)
		);

	board[cruiser[0][0]][cruiser[0][1]][0] = 1;
	board[cruiser[0][0]][cruiser[0][1]][1] = player;
	board[cruiser[0][0]][cruiser[0][1]][2] = 1;

	board[cruiser[1][0]][cruiser[1][1]][0] = 1;
	board[cruiser[1][0]][cruiser[1][1]][1] = player;
	board[cruiser[1][0]][cruiser[1][1]][2] = 1;
}


void placeAC(int player, int board[][8][4])
{
	static int ac[5][2];

	do
	{
		ac[0][0] = rand() % 8;
		ac[0][1] = rand() % 8;

		switch (player)
		{
		case 0:
			ac[1][0] = ac[0][0];
			ac[1][1] = ac[0][1] + 1;

			ac[2][0] = ac[1][0];
			ac[2][1] = ac[1][1] + 1;

			ac[3][0] = ac[2][0];
			ac[3][1] = ac[2][1] + 1;

			ac[4][0] = ac[3][0];
			ac[4][1] = ac[3][1] + 1;

			ac[5][0] = ac[4][0];
			ac[5][1] = ac[4][1] + 1;
			break;
		case 1:
			ac[1][0] = ac[0][0] + 1;
			ac[1][1] = ac[0][1];

			ac[2][0] = ac[1][0] + 1;
			ac[2][1] = ac[1][1];

			ac[3][0] = ac[2][0] + 1;
			ac[3][1] = ac[2][1];

			ac[4][0] = ac[3][0] + 1;
			ac[4][1] = ac[3][1];

			ac[5][0] = ac[4][0] + 1;
			ac[5][1] = ac[4][1];
			break;
		}
	} while (inUse(ac[0], board)
		|| inUse(ac[1], board)
		|| inUse(ac[2], board)
		|| inUse(ac[3], board)
		|| inUse(ac[4], board)
		);

	board[ac[0][0]][ac[0][1]][0] = 1;
	board[ac[0][0]][ac[0][1]][1] = player;
	board[ac[0][0]][ac[0][1]][2] = 2;

	board[ac[1][0]][ac[1][1]][0] = 1;
	board[ac[1][0]][ac[1][1]][1] = player;
	board[ac[1][0]][ac[1][1]][2] = 2;

	board[ac[2][0]][ac[2][1]][0] = 1;
	board[ac[2][0]][ac[2][1]][1] = player;
	board[ac[2][0]][ac[2][1]][2] = 2;

	board[ac[3][0]][ac[3][1]][0] = 1;
	board[ac[3][0]][ac[3][1]][1] = player;
	board[ac[3][0]][ac[3][1]][2] = 2;

	board[ac[4][0]][ac[4][1]][0] = 1;
	board[ac[4][0]][ac[4][1]][1] = player;
	board[ac[4][0]][ac[4][1]][2] = 2;
}


void placeBS(int player, int board[][8][4])
{
	static int bs[4][2];

	do
	{
		bs[0][0] = rand() % 8;
		bs[0][1] = rand() % 8;

		switch (player)
		{
		case 0:
			bs[1][0] = bs[0][0] + 1;
			bs[1][1] = bs[0][1];

			bs[2][0] = bs[1][0] + 1;
			bs[2][1] = bs[1][1];

			bs[3][0] = bs[2][0] + 1;
			bs[3][1] = bs[2][1];

			bs[4][0] = bs[3][0] + 1;
			bs[4][1] = bs[3][1];
			break;
		case 1:
			bs[1][0] = bs[0][0];
			bs[1][1] = bs[0][1] + 1;

			bs[2][0] = bs[1][0];
			bs[2][1] = bs[1][1] + 1;

			bs[3][0] = bs[2][0];
			bs[3][1] = bs[2][1] + 1;

			bs[4][0] = bs[3][0];
			bs[4][1] = bs[3][1] + 1;
			break;
		}
	} while (inUse(bs[0], board)
		|| inUse(bs[1], board)
		|| inUse(bs[2], board)
		|| inUse(bs[3], board)
		);

	board[bs[0][0]][bs[0][1]][0] = 1;
	board[bs[0][0]][bs[0][1]][1] = player;
	board[bs[0][0]][bs[0][1]][2] = 3;

	board[bs[1][0]][bs[1][1]][0] = 1;
	board[bs[1][0]][bs[1][1]][1] = player;
	board[bs[1][0]][bs[1][1]][2] = 3;

	board[bs[2][0]][bs[2][1]][0] = 1;
	board[bs[2][0]][bs[2][1]][1] = player;
	board[bs[2][0]][bs[2][1]][2] = 3;

	board[bs[3][0]][bs[3][1]][0] = 1;
	board[bs[3][0]][bs[3][1]][1] = player;
	board[bs[3][0]][bs[3][1]][2] = 3;
}


void placeSB(int player, int board[][8][4])
{
	static int sb[3][2];

	do
	{
		sb[0][0] = rand() % 8;
		sb[0][1] = rand() % 8;

		switch (player)
		{
		case 0:
			sb[1][0] = sb[0][0];
			sb[1][1] = sb[0][1] + 1;

			sb[2][0] = sb[1][0];
			sb[2][1] = sb[1][1] + 1;

			sb[3][0] = sb[2][0];
			sb[3][1] = sb[2][1] + 1;
			break;
		case 1:
			sb[1][0] = sb[0][0] + 1;
			sb[1][1] = sb[0][1];

			sb[2][0] = sb[1][0] + 1;
			sb[2][1] = sb[1][1];

			sb[3][0] = sb[2][0] + 1;
			sb[3][1] = sb[2][1];
			break;
		}
	} while (inUse(sb[0], board)
		|| inUse(sb[1], board)
		|| inUse(sb[2], board)
		);

	board[sb[0][0]][sb[0][1]][0] = 1;
	board[sb[0][0]][sb[0][1]][1] = player;
	board[sb[0][0]][sb[0][1]][2] = 4;

	board[sb[1][0]][sb[1][1]][0] = 1;
	board[sb[1][0]][sb[1][1]][1] = player;
	board[sb[1][0]][sb[1][1]][2] = 4;

	board[sb[2][0]][sb[2][1]][0] = 1;
	board[sb[2][0]][sb[2][1]][1] = player;
	board[sb[2][0]][sb[2][1]][2] = 4;
}


void placeDS(int player, int board[][8][4])
{
	static int ds[3][2];

	do
	{
		ds[0][0] = rand() % 8;
		ds[0][1] = rand() % 8;

		switch (player)
		{
		case 0:
			ds[1][0] = ds[0][0] + 1;
			ds[1][1] = ds[0][1];

			ds[2][0] = ds[1][0] + 1;
			ds[2][1] = ds[1][1];

			ds[3][0] = ds[2][0] + 1;
			ds[3][1] = ds[2][1];
			break;
		case 1:
			ds[1][0] = ds[0][0];
			ds[1][1] = ds[0][1] + 1;

			ds[2][0] = ds[1][0];
			ds[2][1] = ds[1][1] + 1;

			ds[3][0] = ds[2][0];
			ds[3][1] = ds[2][1] + 1;
			break;
		}
	} while (inUse(ds[0], board)
		|| inUse(ds[1], board)
		|| inUse(ds[2], board)
		);

	board[ds[0][0]][ds[0][1]][0] = 1;
	board[ds[0][0]][ds[0][1]][1] = player;
	board[ds[0][0]][ds[0][1]][2] = 5;

	board[ds[1][0]][ds[1][1]][0] = 1;
	board[ds[1][0]][ds[1][1]][1] = player;
	board[ds[1][0]][ds[1][1]][2] = 5;

	board[ds[2][0]][ds[2][1]][0] = 1;
	board[ds[2][0]][ds[2][1]][1] = player;
	board[ds[2][0]][ds[2][1]][2] = 5;
}
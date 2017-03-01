/*
*	Assignment: Exam Two Battleship
*	Author:  Jacob Butler
*	Date: 2/28/2017
*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef battleship_h
#define battleship_h

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "BattleshipHeader.h"
#define clr() system("clear")

// the main menu
void menu(int *choice);

// not used outside main
void turn(int *round, int board[][8][4], FILE *leaders, char leaderNames[][20], int *leaderScores);
void leader(FILE *leaders);
void fill(int board[][8][4]);

// used outside main
void draw(int *round, int board[][8][4]);
int inUse(int *square, int board[][8][4]);
void placeCruiser(int player, int board[][8][4]);
void placeAC(int player, int board[][8][4]);
void placeBS(int player, int board[][8][4]);
void placeSB(int player, int board[][8][4]);
void placeDS(int player, int board[][8][4]);

int notOver(int board[][8][4]);
int checkFire(int *round, int guess[2], int board[][8][4]);

#endif
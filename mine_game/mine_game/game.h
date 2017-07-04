
#ifndef  __GAME_H__
#define __GAME_H__


#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define ROWS 10
#define COLS 10

#define MINE_COUNT 90


void display(char board[ROWS+2][COLS+2],int row,int col);
void set_mine(char mine[ROWS+2][COLS+2],int row,int col);
//void set_mine_one(char mine[ROWS+2][COLS+2],int row,int col);
//void set_mine_two(char mine[ROWS+2][COLS+2],int row,int col);
//void set_mine_three(char mine[ROWS+2][COLS+2],int row,int col);
int  ground_mine_count(char board[ROWS][COLS],int x,int y);
void play_game(char mine[ROWS+2][COLS+2],char show[ROWS+2][COLS+2]);










#endif  //__GAME_H__
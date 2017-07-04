#include "game.h"


void display(char board[ROWS+2][COLS+2],int row,int col)
{
	int i = 0;
	int j = 0;
	printf("     ");
	for(i=1; i<row-1; i++)
	{
		
		printf("% d",i);
	}
		printf("\n");
	for(i=1; i<row-1; i++)
	{
		printf("   ");
		printf("%2d ",i);
		for(j=1; j<col-1; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}





int get_random_num(int m,int n)
{
	//int ret;
	//ret = rand()%(n-m+1)+m;
	return rand()%(n-m+1)+m;
}



void set_mine(char mine[ROWS+2][COLS+2],int row,int col)
{

	int count = MINE_COUNT;
    while(count)
	{
		int i = get_random_num(1,10);
		int j = get_random_num(1,10);
		//int i = rand()%10+1;
		//int j = rand()%10+1;
		if(mine[i][j] == '0')
		{
			mine[i][j] = '1';
			count--;
		}
	}
}



//void set_mine_two(char mine[ROWS+2][COLS+2],int row,int col)
//{
//
//	int count = 40;
//	while(count)
//	{
//		int i = get_random_num(1,10);
//		int j = get_random_num(1,10);
//		//int i = rand()%10+1;
//		//int j = rand()%10+1;
//		if(mine[i][j] == '0')
//		{
//			mine[i][j] = '1';
//			count--;
//		}
//	}
//}
//
//
//void set_mine_three(char mine[ROWS+2][COLS+2],int row,int col)
//{
//
//	int count = 60;
//	while(count)
//	{
//		int i = get_random_num(1,10);
//		int j = get_random_num(1,10);
//		//int i = rand()%10+1;
//		//int j = rand()%10+1;
//		if(mine[i][j] == '0')
//		{
//			mine[i][j] = '1';
//			count--;
//		}
//	}
//}


int  ground_mine_count(char board[ROWS+2][COLS+2],int x,int y)
{
	return (board[x-1][y-1]-'0')+
		(board[x][y-1]-'0')+
		(board[x+1][y-1]-'0')+
		(board[x+1][y]-'0')+
		(board[x+1][y+1]-'0')+
		(board[x][y+1]-'0')+
		(board[x-1][y+1]-'0')+ 
		(board[x-1][y]-'0');

}




void play_game(char mine[ROWS+2][COLS+2],char show[ROWS+2][COLS+2])
{
	while(1)
	{
		int win = 0;
		int x = 0,y = 0;
		printf("请输入坐标>: ");
		scanf("%d%d",&x,&y);
		if(((x>=1)&&(x<=10))&&((y>=1)&&(y<=10)))
		{
			if(mine[x][y] == '1')
			{
				printf("gameover\n");
				display(mine,ROWS,COLS);
				break;
			}
			else
			{
				int ret = 0;
				win++;
				ret = ground_mine_count(mine,x,y);
				show[x][y] = ret + '0';
				display(show,ROWS+2,COLS+2);
				if(win == COLS*ROWS-MINE_COUNT)
				{
					printf("恭喜你胜利了！\n");
					display(mine,ROWS,COLS);
					break;
				}
			}

		}
		else
		{
			printf("输入错误，请重新输入！");
		}
	}
}
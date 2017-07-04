#define _CRT_SECURE_NO_DEPRECATE 

#include "game.h"




void menu()
{
	printf("-----------------------------------\n");
	printf("|      请选择：                   |\n");
	printf("|             1.开始游戏          |\n");
	printf("|             0.退出游戏          |\n");
	printf("-----------------------------------\n");
}


void mine_menu()
{
	printf("------------------------------------\n");
	printf("|   请选择等级：                   |\n");
	printf("|             1.初级               |\n");
	printf("|             2.中级               |\n");
	printf("|             3.高级               |\n");
	printf("------------------------------------\n");

}


void game ()
{
	//int input= 0;
 //   do 
 //   {
	//	mine_menu();
	//	printf("请选择等级>: ");
	//	scanf("%d",&input);
	//	switch(input)
	//	{
	//	case 1:
	//		{
	//			char mine[ROWS+2][COLS+2];
	//			char show[ROWS+2][COLS+2];
	//			srand( (unsigned)time( NULL ) );
	//			memset(mine,'0',(ROWS+2)*(COLS+2)*sizeof(char));
	//			memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char));
	//			display(show,ROWS+2,COLS+2);
	//			set_mine_one(mine,ROWS+2,COLS+2);
	//			display(mine,ROWS+2,COLS+2);
	//			play_game(mine,show);
	//			break;

	//		}
	//
	//	case 2:
	//		{
	//			char mine[ROWS+2][COLS+2];
	//			char show[ROWS+2][COLS+2];
	//			srand( (unsigned)time( NULL ) );
	//			memset(mine,'0',(ROWS+2)*(COLS+2)*sizeof(char));
	//			memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char));
	//			display(show,ROWS+2,COLS+2);
	//			set_mine_two(mine,ROWS+2,COLS+2);
	//			display(mine,ROWS+2,COLS+2);
	//			play_game(mine,show);
	//			break;

	//		}
	//	case 3:
	//		{
	//			char mine[ROWS+2][COLS+2];
	//			char show[ROWS+2][COLS+2];
	//			srand( (unsigned)time( NULL ) );
	//			memset(mine,'0',(ROWS+2)*(COLS+2)*sizeof(char));
	//			memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char));
	//			display(show,ROWS+2,COLS+2);
	//			set_mine_three(mine,ROWS+2,COLS+2);
	//			display(mine,ROWS+2,COLS+2);
	//			play_game(mine,show);
	//			break;
	//		}
	//		
	//	default:
	//		printf("输入错误，请重新输入！\n");
	//		break;
	//} while (input);
	//	


	//}
	
	char mine[ROWS+2][COLS+2];
	char show[ROWS+2][COLS+2];
	srand( (unsigned)time( NULL ) );
	memset(mine,'0',(ROWS+2)*(COLS+2)*sizeof(char));
	memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char));
	display(show,ROWS+2,COLS+2);
	set_mine(mine,ROWS+2,COLS+2);
	display(mine,ROWS+2,COLS+2);
	play_game(mine,show);
}



int main()
{
	
	int input = 0;
	system("color 30");
	do 
	{
		menu();
		printf("请输入你的选择：> ");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
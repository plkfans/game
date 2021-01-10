#include<stdio.h>
#include"game.h"
void menu() {
	printf("**************************************\n");
	printf("*****     1.PLAY    0.exit();   ******\n");
	printf("**************************************\n");

}
void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PalyerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢。\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢。\n");
	}
	else
	{
		printf("平局。\n");
	}
}
void test() 
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：\n");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏。\n");
				break;
			default:
				printf("输入有误，请重新输入：\n");
				break;

		}
	} while (input);
	
}


int main() {	
	test();
	return 0;
}
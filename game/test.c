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
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ�֡�\n");
	}
}
void test() 
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ��\n");
				break;
			default:
				printf("�����������������룺\n");
				break;

		}
	} while (input);
	
}


int main() {	
	test();
	return 0;
}
#include<iostream>
using namespace std;

int main()
{
	const int ROWS = 3;
	const int COLUMNS = 3;

	char board[ROWS][COLUMNS] = { { 'O','X','O' },
	{ ' ','X','X' },
	{ 'X','O','O' } };
	cout << "这里是#字棋盘:\n";
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "\n‘X’移到空位置.\n\n";
	board[1][0] = 'X';
	cout << "现在的#字棋盘是：\n";
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "\n‘X’获胜！" << endl;
	cout << endl;
	system("pause");
	return 0;
}
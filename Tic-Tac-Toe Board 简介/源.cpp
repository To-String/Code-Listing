#include<iostream>
using namespace std;

int main()
{
	const int ROWS = 3;
	const int COLUMNS = 3;

	char board[ROWS][COLUMNS] = { { 'O','X','O' },
	{ ' ','X','X' },
	{ 'X','O','O' } };
	cout << "������#������:\n";
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "\n��X���Ƶ���λ��.\n\n";
	board[1][0] = 'X';
	cout << "���ڵ�#�������ǣ�\n";
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "\n��X����ʤ��" << endl;
	cout << endl;
	system("pause");
	return 0;
}
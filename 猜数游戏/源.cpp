#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));   //Ϊ�����������ȷ������
	int secretNumber = rand() % 100 + 1;           //�������1~100֮��
	int tries = 0;
	int guess;
	cout << "\t��ӭ������������Ϸ.\n\n";
	do
	{
		cout << "����һ�����������в²⣺";
		cin >> guess;
		++tries;

		if (guess > secretNumber)
		{
			cout << "��²��̫���ˣ�\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "��²��̫���ˣ�\n\n";
		}
		else
		{
			cout << "������" << tries << "�ξͲ¶��ˣ�\n";
		}
	} while (guess != secretNumber);
	system("pause");
	return 0;

}
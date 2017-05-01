#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));   //为随机数生成器确定种子
	int secretNumber = rand() % 100 + 1;           //随机数在1~100之间
	int tries = 0;
	int guess;
	cout << "\t欢迎来到猜数字游戏.\n\n";
	do
	{
		cout << "输入一个正数，进行猜测：";
		cin >> guess;
		++tries;

		if (guess > secretNumber)
		{
			cout << "你猜测的太高了！\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "你猜测的太低了！\n\n";
		}
		else
		{
			cout << "你用了" << tries << "次就猜对了！\n";
		}
	} while (guess != secretNumber);
	system("pause");
	return 0;

}
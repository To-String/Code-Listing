#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{//选择一个单词来打乱顺序，玩家将要猜的就是这个单词
	enum fields
	{
		WORD, HINT, NUM_FIELDS
	};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{ "wall","Do you feel you are banging you head against something？" },
		{ "glasses"," These might help you see the answer." },
		{ "labored","Going slowly,is it？" },
		{ "persistent","Kepp at it." },
		{ "jumble","It is what the game is all about." }
	};
	//随机选择一个单词
	srand(static_cast <unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];           //猜词
	string theHint = WORDS[choice][HINT];        //提示词

	string jumble = theWord;  //给单词生成一个乱序版本
	int length = jumble.size();
	for (int i = 0; i < length; i++)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	//告诉玩家操作指南，包括如何退出游戏和如何请求提示
	cout << "\t\t欢迎来到字谜游戏！\n\n";
	cout << "把字母整理成原来的样子.\n";
	cout << "输入‘hint’出现提示.\n";
	cout << "输入‘quit’退出游戏.\n\n";
	cout << "搞乱是：" << jumble;
	string guess;
	cout << "\n\n你的猜测：";
	cin >> guess;

	//游戏主循环
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "对不起，猜错了.";
		}
	}
	cout << "\n\n你的猜测：";
	cin >> guess;
	if (guess == theWord)
	{
		cout << "\n是，你猜对了！\n";
	}
	cout << "\n感谢您的参与！\n";
	cout << endl;
	system("pause");
	return 0;
}
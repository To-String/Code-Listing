#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cctype>
using namespace std;

int main()
{
	const int MAX_WRONG = 8;  //允许玩家猜错的最多次数
	vector<string>words;            //包含可能猜测的单词
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];    //猜单词
	int wrong = 0;                                      //错误猜测数
	string soFar(THE_WORD.size(), '-');            //目前所猜的单词
	string used = "";                            //猜到字母 
	cout << "欢饮来到Hangman,祝你好运!\n";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\n你还有" << (MAX_WRONG - wrong);
		cout << "次不正确的猜测.\n";
		cout << "\n你使用了以下字母：\n" << used << endl;
		cout << "\n到目前为止，这个词是：\n" << soFar << endl;

		char guess;
		cout << "\n\n输入你的猜测：";
		cin >> guess;
		guess = toupper(guess);
		while (used.find(guess) != string::npos)
		{
			cout << "\n你已经猜到了" << guess << endl;
			cout << "输入你的猜测：";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "那个是正确的！" << guess << "是在这个词里.\n";
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "对不起，" << guess << "不在里面.\n";
			++wrong;
		}
	}
	if (wrong == MAX_WRONG)
	{
		cout << "\n你已被绞死！";
	}
	else
	{
		cout << "\n你猜对了！";
	}
	cout << "\n这个词是：" << THE_WORD << endl;
	cout << endl;
	system("pause");
	return 0;
}
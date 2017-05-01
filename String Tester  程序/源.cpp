#include<iostream>
#include<string>
using namespace std;

int main()
{
	string word1 = "Game";
	string word2("Over");
	string word3(3, '!');

	string Phrase = word1 + " " + word2 + word3;
	cout << "这个短语是：" << Phrase << "\n\n";

	cout << "这句短语有" << Phrase.size() << "个字符.\n\n";
	cout << "这个短语的第0位是：" << Phrase[0] << "\n\n";
	cout << "现在改变位置0的字符\n";
	Phrase[0] = 'L';
	cout << "现在的短语是：" << Phrase << "\n\n";

	for (unsigned int i = 0; i < Phrase.size(); i++)
	{
		cout << "现在在位置" << i << "的是：" << Phrase[i] << endl;
	}
	cout << "\n‘Over'序列在位置" << Phrase.find("Over") << endl;
	if (Phrase.find("eggplant") == string::npos)
	{
		cout << "'eggplant'不在短语中.\n\n";
	}
	Phrase.erase(4, 5);
	cout << "现在的短语是：" << Phrase << endl;
	Phrase.erase(4);
	cout << "现在的短语是：" << Phrase << endl;

	Phrase.erase();
	cout << "现在的短语是：" << Phrase << endl;

	if (Phrase.empty())
	{
		cout << "\n现在没有短语了.\n";
	}
	cout << endl;
	system("pause");
	return 0;
}
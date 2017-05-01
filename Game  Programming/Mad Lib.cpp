#include<iostream>
#include<string>
using namespace std;
string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodypart, string verb);
int main()
{
	cout << "欢迎来到 Mad Lid.\n\n";
	cout << "回答以下故事，帮忙创建一个新的故事.\n";
	string name = askText("请输入姓名:");
	string noun = askText("请输入复数名词:");
	int number = askNumber("请输入数字:");
	string bodypart = askText("请输入正文部分:");
	string verb = askText("请输入动词:");
	tellStory(name, noun, number, bodypart, verb);
	cout << endl;
	system("pause");
	return 0;
}
string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}
int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}
void tellStory(string name, string noun, int number, string bodypart, string verb)
{
	cout << "\nHere is your story:\n";
	cout << "The famous explorer";
	cout << name;
	cout << "had nerly given up a life-long quesr to find\n";
	cout << "The Lost City of ";
	cout << noun;
	cout << " when one day,the ";
	cout << noun;
	cout << " found the explorer.\n";
	cout << "Surrounded by ";
	cout << number;
	cout << " " << noun;
	cout << ", a tear came to ";
	cout << name << "'s ";
	cout << bodypart << ".\n";
	cout << "After all this time,the quest was finally over.";
	cout << "And them,the ";
	cout << noun << "\n";
	cout << "promptly devoured";
	cout << name << ".";
	cout << "The moral of the story? Be careful what you";
	cout << verb;
	cout << "for.";
	
}
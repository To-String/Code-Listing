#include<iostream>
#include<string>
using namespace std;
string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodypart, string verb);
int main()
{
	cout << "��ӭ���� Mad Lid.\n\n";
	cout << "�ش����¹��£���æ����һ���µĹ���.\n";
	string name = askText("����������:");
	string noun = askText("�����븴������:");
	int number = askNumber("����������:");
	string bodypart = askText("���������Ĳ���:");
	string verb = askText("�����붯��:");
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
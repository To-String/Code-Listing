#include<iostream>
#include<string>
using namespace std;

int main()
{
	int *pScore = 0;
	int score = 1000;
	pScore = &score;
	cout << "&score �����ĵ�ַ" << endl;
	cout << "&scre is:" << &score << endl;
	cout << "pScore is:" << pScore << endl;
	cout << "score is:" << score << endl;
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "score�ټ�500\n";
	score += 500;
	cout << "score is:" << score << endl;
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "*pScore ����500\n";
	*pScore += 500;
	cout << "score is:" << score << endl;
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "pScore����ָ���µı���&newScore\n";
	int newScore = 5000;
	pScore = &newScore;
	cout << "&newScore is:" << &newScore << endl;
	cout << "pScore is:" << pScore << endl;
	cout << "newScore is:" << newScore << endl;
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "ָ�����pStrָ��&str\n";
	string str = "score";
	string *pStr = &str;
	 
	cout << "str is:" << str << endl;
	cout << "*pStr is:" << *pStr << endl;
	cout << "(*pStr).size() is:" << (*pStr).size() << endl;
	cout << "pStr->size() is:" << pStr->size() << endl << endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int *pScore = 0;
	int score = 1000;
	pScore = &score;
	cout << "&score 变量的地址" << endl;
	cout << "&scre is:" << &score << endl;
	cout << "pScore is:" << pScore << endl;
	cout << "score is:" << score << endl;
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "score再加500\n";
	score += 500;
	cout << "score is:" << score << endl;
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "*pScore 增加500\n";
	*pScore += 500;
	cout << "score is:" << score << endl;
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "pScore重新指向新的变量&newScore\n";
	int newScore = 5000;
	pScore = &newScore;
	cout << "&newScore is:" << &newScore << endl;
	cout << "pScore is:" << pScore << endl;
	cout << "newScore is:" << newScore << endl;
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "指针变量pStr指向&str\n";
	string str = "score";
	string *pStr = &str;
	 
	cout << "str is:" << str << endl;
	cout << "*pStr is:" << *pStr << endl;
	cout << "(*pStr).size() is:" << (*pStr).size() << endl;
	cout << "pStr->size() is:" << pStr->size() << endl << endl;
	system("pause");
	return 0;
}
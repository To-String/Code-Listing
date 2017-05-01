#include<iostream>
#include<string>
#include<vector>
using namespace std;

string *ptrToElement(vector<string> *const pVec, int i);
int main()
{
	vector<string>inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	cout << "用cout输出返回的指针所指向的对象：\n";
	cout << *(ptrToElement(&inventory, 0)) << "\n\n";

	cout << "将返回的指针赋值给另一个指针.\n";
	string *pStr = ptrToElement(&inventory, 1);
	cout << "用cout输出新的指针所指向的对象:\n";
	cout << *pStr << "\n\n";

	cout << "将指针所指向的对象赋值给一个字符串变量.\n";
	string str = *(ptrToElement(&inventory, 2));
	cout << "用cout输出新的字符串变量：\n";
	cout << str << "\n\n";

	cout << "通过返回的指针改变一个对象.\n";
	*pStr = "Healing Potion";
	cout << "用cout输出改变的对象：\n";
	cout << inventory[1] << "\n\n";
	system("pause");
	return 0;
}
string *ptrToElement(vector<string> *const pVec, int i)
{
	return &((*pVec)[i]);
}
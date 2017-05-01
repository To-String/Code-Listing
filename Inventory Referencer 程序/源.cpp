#include<iostream>
#include<string>
#include<vector>
using namespace std;
string &refToElement(vector<string>&inventory, int i);
int main()
{
	vector<string>inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	cout << "用cout输出返回的引用：\n";
	cout << refToElement(inventory, 0) << "\n\n";

	cout << "将返回的引用分配给另一个引用.\n";
	string &rStr = refToElement(inventory, 1);
	cout << "用cout输出新返回的引用：\n";
	cout << rStr << "\n\n";

	cout << "将返回的引用分配给字符串对象.\n";
	string str = refToElement(inventory, 2);
	cout << "用cout输出新的字符串对象：\n";
	cout << str << "\n\n";

	cout << "通过返回的引用改变对象.\n";
	rStr = "Healing potion";
	cout << "用cout输出改变的对象：\n";
	cout << inventory[1] << endl;

	cout << endl;
	system("pause");
	return 0;
}
string &refToElement(vector<string>&vec, int i)
{
	return vec[i];
}
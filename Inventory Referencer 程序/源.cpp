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

	cout << "��cout������ص����ã�\n";
	cout << refToElement(inventory, 0) << "\n\n";

	cout << "�����ص����÷������һ������.\n";
	string &rStr = refToElement(inventory, 1);
	cout << "��cout����·��ص����ã�\n";
	cout << rStr << "\n\n";

	cout << "�����ص����÷�����ַ�������.\n";
	string str = refToElement(inventory, 2);
	cout << "��cout����µ��ַ�������\n";
	cout << str << "\n\n";

	cout << "ͨ�����ص����øı����.\n";
	rStr = "Healing potion";
	cout << "��cout����ı�Ķ���\n";
	cout << inventory[1] << endl;

	cout << endl;
	system("pause");
	return 0;
}
string &refToElement(vector<string>&vec, int i)
{
	return vec[i];
}
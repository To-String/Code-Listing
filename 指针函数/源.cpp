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

	cout << "��cout������ص�ָ����ָ��Ķ���\n";
	cout << *(ptrToElement(&inventory, 0)) << "\n\n";

	cout << "�����ص�ָ�븳ֵ����һ��ָ��.\n";
	string *pStr = ptrToElement(&inventory, 1);
	cout << "��cout����µ�ָ����ָ��Ķ���:\n";
	cout << *pStr << "\n\n";

	cout << "��ָ����ָ��Ķ���ֵ��һ���ַ�������.\n";
	string str = *(ptrToElement(&inventory, 2));
	cout << "��cout����µ��ַ���������\n";
	cout << str << "\n\n";

	cout << "ͨ�����ص�ָ��ı�һ������.\n";
	*pStr = "Healing Potion";
	cout << "��cout����ı�Ķ���\n";
	cout << inventory[1] << "\n\n";
	system("pause");
	return 0;
}
string *ptrToElement(vector<string> *const pVec, int i)
{
	return &((*pVec)[i]);
}
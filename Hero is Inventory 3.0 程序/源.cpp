#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string>inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	vector<string>::iterator myIterator;
	vector<string>::const_iterator item;
	cout << "�����Ʒ�У�\n";
	for (item = inventory.begin(); item != inventory.end(); ++item)
	{
		cout << *item << endl;
	}
	cout << "\n���ý���ս��.";
	myIterator = inventory.begin();
	*myIterator = "battle axe";
	cout << "\n�����Ʒ�У�\n";
	for (item = inventory.begin(); item != inventory.end(); ++item)
	{
		cout << *item << endl;
	}
	cout << "\n��Ʒ���ơ�" << *myIterator << "����" << (*myIterator).size() << "����ĸ\n";
	cout << "\n��Ʒ���ơ�" << *myIterator << "����" << myIterator->size() << "����ĸ\n";

	cout << "\n���һ����ɱ�õ���������һ��ʯ��.";
	inventory.insert(inventory.begin(), "crossbow");
	cout << "\n�����Ʒ�У�\n";
	for (item = inventory.begin(); item != inventory.end(); ++item)
	{
		cout << *item << endl;
	}
	cout << "\n��Ŀ�����ս���б�����.";
	inventory.erase((inventory.begin() + 2));
	cout << "\n�����Ʒ�У�\n";
	for (item = inventory.begin(); item != inventory.end(); ++item)
	{
		cout << *item << endl;
	}
	cout << endl;
	system("pause");
	return 0;

}
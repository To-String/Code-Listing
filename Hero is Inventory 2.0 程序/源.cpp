#include<iostream>
#include<vector>
#include<string>
using namespace  std;

int main()
{
	vector<string>inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	cout << "����" << inventory.size() << "����Ʒ.\n";
	cout << "\n�����Ʒ�У�\n";
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n���ý�����ս��.";
	inventory[0] = "battle axe";
	cout << "\n�����Ʒ�У�\n";
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n��Ʒ�����ơ�" << inventory[0] << "����" << inventory[0].size() << "����ĸ.\n";
	cout << "\n��Ķ���ս���б�����.";
	inventory.pop_back();
	cout << "\n�����Ʒ�У�\n";
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n�㱻�����������е���Ʒ.";
	inventory.clear();
	if (inventory.empty())
	{
		cout << "\n������ʲô��û����.\n";
	}
	else
	{
		cout << "\n���������ٻ���һ����Ʒ.\n";
	}
	cout << endl;
	system("pause");
	return 0;

}
#include<iostream>
#include<string>

using namespace std;

int main()
{
	const int MAX_ITEMS = 10;
	string inventory[MAX_ITEMS];
	int numItems = 0;
	inventory[numItems++] = "��";
	inventory[numItems++] = "����";
	inventory[numItems++] = "��";
	cout << "������Ʒ��:\n";
	for (int i = 0; i < numItems; i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n������ý���ս��.";
	inventory[0] = "ս��";
	cout << "\n������Ʒ�У�\n";
	for (int i = 0; i < numItems; i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n��Ʒ���ơ�" << inventory[0] << "'��" << inventory[0].size() << "����ĸ.\n";
	cout << "\n���ҵ�һ������ҩˮ.";
	if (numItems < MAX_ITEMS)
	{
		inventory[numItems++] = "����ҩˮ";
	}
	else
	{
		cout << "�����Ʒ̫�࣬����Я����.";
	}
	cout << "\n������Ʒ��:\n";
	for (int i = 0; i < numItems; i++)
	{
		cout << inventory[i] << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<string>

using namespace std;

int main()
{
	const int MAX_ITEMS = 10;
	string inventory[MAX_ITEMS];
	int numItems = 0;
	inventory[numItems++] = "剑";
	inventory[numItems++] = "盔甲";
	inventory[numItems++] = "盾";
	cout << "您的物品有:\n";
	for (int i = 0; i < numItems; i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n你可以用剑换战斧.";
	inventory[0] = "战斧";
	cout << "\n您的物品有：\n";
	for (int i = 0; i < numItems; i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n物品名称‘" << inventory[0] << "'有" << inventory[0].size() << "个字母.\n";
	cout << "\n你找到一个治疗药水.";
	if (numItems < MAX_ITEMS)
	{
		inventory[numItems++] = "治疗药水";
	}
	else
	{
		cout << "你的物品太多，不能携带了.";
	}
	cout << "\n您的物品有:\n";
	for (int i = 0; i < numItems; i++)
	{
		cout << inventory[i] << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
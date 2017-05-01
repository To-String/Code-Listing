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
	cout << "你的物品有：\n";
	for (item = inventory.begin(); item != inventory.end(); ++item)
	{
		cout << *item << endl;
	}
	cout << "\n你用剑换战斧.";
	myIterator = inventory.begin();
	*myIterator = "battle axe";
	cout << "\n你的物品有：\n";
	for (item = inventory.begin(); item != inventory.end(); ++item)
	{
		cout << *item << endl;
	}
	cout << "\n物品名称‘" << *myIterator << "’有" << (*myIterator).size() << "个字母\n";
	cout << "\n物品名称‘" << *myIterator << "’有" << myIterator->size() << "个字母\n";

	cout << "\n你从一个被杀得敌人那里获得一把石弓.";
	inventory.insert(inventory.begin(), "crossbow");
	cout << "\n你的物品有：\n";
	for (item = inventory.begin(); item != inventory.end(); ++item)
	{
		cout << *item << endl;
	}
	cout << "\n你的盔甲在战斗中被销毁.";
	inventory.erase((inventory.begin() + 2));
	cout << "\n你的物品有：\n";
	for (item = inventory.begin(); item != inventory.end(); ++item)
	{
		cout << *item << endl;
	}
	cout << endl;
	system("pause");
	return 0;

}
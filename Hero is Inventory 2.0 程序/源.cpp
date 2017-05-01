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
	cout << "你有" << inventory.size() << "个物品.\n";
	cout << "\n你的物品有：\n";
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n你用剑换了战斧.";
	inventory[0] = "battle axe";
	cout << "\n你的物品有：\n";
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n物品的名称‘" << inventory[0] << "’有" << inventory[0].size() << "个字母.\n";
	cout << "\n你的盾在战斗中被销毁.";
	inventory.pop_back();
	cout << "\n你的物品有：\n";
	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}
	cout << "\n你被贼抢走了所有的物品.";
	inventory.clear();
	if (inventory.empty())
	{
		cout << "\n你现在什么都没有了.\n";
	}
	else
	{
		cout << "\n你现在至少还有一件物品.\n";
	}
	cout << endl;
	system("pause");
	return 0;

}
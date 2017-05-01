#include<iostream>
#include<string>
#include<string>
#include<vector>
using namespace std;
void display(const vector<string>& inventory);
int main()
{
	vector<string>inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	display(inventory);
	cout << endl;
	system("pause");
	return 0;
}
void display(const vector<string>& inventory)
{
	cout << "你的物品有：\n";
	for (vector<string>::const_iterator iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout << *iter << endl;
	}
}
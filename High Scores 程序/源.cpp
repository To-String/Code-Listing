#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	vector<int>::const_iterator iter;
	cout << "创建了一个分数列表.";
	vector<int>scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);
	cout << "\n分数有：\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << "\n查找分数.";
	int score;
	cout << "\n输入一个要查找的分数：";
	cin >> score;
	iter = find(scores.begin(), scores.end(), score);
	if (iter != scores.end())
	{
		cout << "找到分数.\n";
	}
	else
	{
		cout << "没有找到分数.\n";
	}
	cout << "\n随机的分数.";
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(scores.begin(), scores.end());
	cout << "\n高分数有：\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << "\n排序分数.";
	sort(scores.begin(), scores.end());
	cout << "\n高分数有：\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
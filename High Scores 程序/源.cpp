#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	vector<int>::const_iterator iter;
	cout << "������һ�������б�.";
	vector<int>scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);
	cout << "\n�����У�\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << "\n���ҷ���.";
	int score;
	cout << "\n����һ��Ҫ���ҵķ�����";
	cin >> score;
	iter = find(scores.begin(), scores.end(), score);
	if (iter != scores.end())
	{
		cout << "�ҵ�����.\n";
	}
	else
	{
		cout << "û���ҵ�����.\n";
	}
	cout << "\n����ķ���.";
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(scores.begin(), scores.end());
	cout << "\n�߷����У�\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << "\n�������.";
	sort(scores.begin(), scores.end());
	cout << "\n�߷����У�\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string word1 = "Game";
	string word2("Over");
	string word3(3, '!');

	string Phrase = word1 + " " + word2 + word3;
	cout << "��������ǣ�" << Phrase << "\n\n";

	cout << "��������" << Phrase.size() << "���ַ�.\n\n";
	cout << "�������ĵ�0λ�ǣ�" << Phrase[0] << "\n\n";
	cout << "���ڸı�λ��0���ַ�\n";
	Phrase[0] = 'L';
	cout << "���ڵĶ����ǣ�" << Phrase << "\n\n";

	for (unsigned int i = 0; i < Phrase.size(); i++)
	{
		cout << "������λ��" << i << "���ǣ�" << Phrase[i] << endl;
	}
	cout << "\n��Over'������λ��" << Phrase.find("Over") << endl;
	if (Phrase.find("eggplant") == string::npos)
	{
		cout << "'eggplant'���ڶ�����.\n\n";
	}
	Phrase.erase(4, 5);
	cout << "���ڵĶ����ǣ�" << Phrase << endl;
	Phrase.erase(4);
	cout << "���ڵĶ����ǣ�" << Phrase << endl;

	Phrase.erase();
	cout << "���ڵĶ����ǣ�" << Phrase << endl;

	if (Phrase.empty())
	{
		cout << "\n����û�ж�����.\n";
	}
	cout << endl;
	system("pause");
	return 0;
}
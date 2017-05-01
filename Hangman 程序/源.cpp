#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cctype>
using namespace std;

int main()
{
	const int MAX_WRONG = 8;  //������Ҳ´��������
	vector<string>words;            //�������ܲ²�ĵ���
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];    //�µ���
	int wrong = 0;                                      //����²���
	string soFar(THE_WORD.size(), '-');            //Ŀǰ���µĵ���
	string used = "";                            //�µ���ĸ 
	cout << "��������Hangman,ף�����!\n";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\n�㻹��" << (MAX_WRONG - wrong);
		cout << "�β���ȷ�Ĳ²�.\n";
		cout << "\n��ʹ����������ĸ��\n" << used << endl;
		cout << "\n��ĿǰΪֹ��������ǣ�\n" << soFar << endl;

		char guess;
		cout << "\n\n������Ĳ²⣺";
		cin >> guess;
		guess = toupper(guess);
		while (used.find(guess) != string::npos)
		{
			cout << "\n���Ѿ��µ���" << guess << endl;
			cout << "������Ĳ²⣺";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "�Ǹ�����ȷ�ģ�" << guess << "�����������.\n";
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "�Բ���" << guess << "��������.\n";
			++wrong;
		}
	}
	if (wrong == MAX_WRONG)
	{
		cout << "\n���ѱ�������";
	}
	else
	{
		cout << "\n��¶��ˣ�";
	}
	cout << "\n������ǣ�" << THE_WORD << endl;
	cout << endl;
	system("pause");
	return 0;
}
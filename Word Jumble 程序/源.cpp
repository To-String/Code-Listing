#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{//ѡ��һ������������˳����ҽ�Ҫ�µľ����������
	enum fields
	{
		WORD, HINT, NUM_FIELDS
	};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{ "wall","Do you feel you are banging you head against something��" },
		{ "glasses"," These might help you see the answer." },
		{ "labored","Going slowly,is it��" },
		{ "persistent","Kepp at it." },
		{ "jumble","It is what the game is all about." }
	};
	//���ѡ��һ������
	srand(static_cast <unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];           //�´�
	string theHint = WORDS[choice][HINT];        //��ʾ��

	string jumble = theWord;  //����������һ������汾
	int length = jumble.size();
	for (int i = 0; i < length; i++)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	//������Ҳ���ָ�ϣ���������˳���Ϸ�����������ʾ
	cout << "\t\t��ӭ����������Ϸ��\n\n";
	cout << "����ĸ�����ԭ��������.\n";
	cout << "���롮hint��������ʾ.\n";
	cout << "���롮quit���˳���Ϸ.\n\n";
	cout << "�����ǣ�" << jumble;
	string guess;
	cout << "\n\n��Ĳ²⣺";
	cin >> guess;

	//��Ϸ��ѭ��
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "�Բ��𣬲´���.";
		}
	}
	cout << "\n\n��Ĳ²⣺";
	cin >> guess;
	if (guess == theWord)
	{
		cout << "\n�ǣ���¶��ˣ�\n";
	}
	cout << "\n��л���Ĳ��룡\n";
	cout << endl;
	system("pause");
	return 0;
}
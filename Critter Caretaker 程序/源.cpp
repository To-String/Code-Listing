#include<iostream>
using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);

private:
	int m_Hunger;
	int m_Boredom;
	int GetMood()const;
	void passTime(int time = 1);
};
Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger),
	m_Boredom(boredom)
{
	
}
inline int Critter::GetMood()const
{
	return (m_Hunger + m_Boredom);
}
void Critter::passTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	cout << "�����ڵ�������";
	int mood = GetMood();
	if(mood > 15)
	{
		cout << "�����ڷ�ŭ��.\n";
	}
	else if (mood > 10)
	{
		cout << "�������Ǿ�ɥ��.\n";
	}
	else if (mood > 5)
	{
		cout << "�������Ǻܺõ�.\n";
	}
	else
	{
		cout << "�������Ƿǳ����˵�.\n";
	}
	passTime();
}
void Critter::Eat(int food)
{
	cout << "Brruppp.\n";
	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}
	passTime();
}
void Critter::Play(int fun)
{
	cout << "wheee!\n";
	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}
	passTime();
}


int main()
{
	Critter crit;
	crit.Talk();
	int choice;
	do
	{
		cout << "\n�������Ա��Ϸ\n\n";
		cout << "��0���˳���Ϸ\n";
		cout << "��1������Ķ���˵��.\n";
		cout << "��2��ι��Ķ���Զ���.\n";
		cout << "��3������Ķ�����ˣ.\n\n";
		cout << "��������Ӧ����ţ�����ѡ��";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "��Ϸ�������ټ���" << endl;
			break;
		case 1:
			crit.Talk();
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		default:
			cout << "���������Ų���ȷ�����������룡\n";
		}
	} while (choice != 0);
	cout << endl;
	system("pause");
	return 0;
}
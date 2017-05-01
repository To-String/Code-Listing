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
	cout << "我现在的情绪是";
	int mood = GetMood();
	if(mood > 15)
	{
		cout << "我现在愤怒的.\n";
	}
	else if (mood > 10)
	{
		cout << "我现在是沮丧的.\n";
	}
	else if (mood > 5)
	{
		cout << "我现在是很好的.\n";
	}
	else
	{
		cout << "我现在是非常高兴的.\n";
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
		cout << "\n动物管理员游戏\n\n";
		cout << "按0，退出游戏\n";
		cout << "按1，听你的动物说话.\n";
		cout << "按2，喂你的动物吃东西.\n";
		cout << "按3，跟你的动物玩耍.\n\n";
		cout << "请输入相应的序号，做出选择：";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "游戏结束，再见！" << endl;
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
			cout << "您输入的序号不正确，请重新输入！\n";
		}
	} while (choice != 0);
	cout << endl;
	system("pause");
	return 0;
}
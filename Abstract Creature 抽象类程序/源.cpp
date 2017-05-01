#include<iostream>
using namespace std;

class Creature
{
public:
	Creature(int health = 100);
	virtual void Greet()const = 0;
	virtual void DisplayHealth()const;
protected:
	int m_Health;
};
Creature::Creature(int health) :
	m_Health(health)
{
	cout << "Creature类的构造函数被调用" << endl;
}
void Creature::DisplayHealth()const
{
	cout << "生命值是：" << m_Health << endl << endl;
}

class Orc :public Creature
{
public:
	Orc(int health = 120);
	virtual void Greet()const;
	virtual void DisplayHealth()const;
protected:
	int m_Qhealth;
};
Orc::Orc(int health) :
	Creature(health),
	m_Qhealth(health)
{
	cout << "Orc类的构造函数被调用" << endl;
}
void Orc::Greet()const
{
	cout << "半兽人向你发出问候！" << endl;
}
void Orc::DisplayHealth()const
{
	cout << "Orc类的生命值是：" << m_Qhealth << endl << endl;
}


class OrcBoss :public Orc
{
public:
	OrcBoss(int health = 180);
	virtual void Greet()const;
	virtual void DisplayHealth()const;
protected:
	int m_health;
};
OrcBoss::OrcBoss(int health):
	Orc(health),
	m_health(health)
{
	cout << "OrcBoss类的构造函数被调用" << endl;
}
void OrcBoss::Greet()const
{
	cout << "The orc boss growls hello. (首领向半兽人问好)" << endl;
}
void OrcBoss::DisplayHealth()const
{
	cout << "OrcBoss类的生命值是：" << m_health << endl << endl;
}

int main()
{
	Creature *pCreature = new Orc();
	pCreature->Greet();
	pCreature->DisplayHealth();

	Creature *myCreature = new OrcBoss();
	myCreature->Greet();
	myCreature->DisplayHealth();
	cout << endl;
	system("pause");										
	return 0;
}


#include<iostream>
using namespace std;

class Enemy
{
public:
	
	Enemy();
	void Attack()const;
protected:
	int m_Damage;
};
Enemy::Enemy()
{
	m_Damage = 10;
	cout << "Enemy��Ĺ��캯��������" << endl;
}
void Enemy::Attack()const
{
	cout << "Enemy��Ĺ������" << m_Damage << "���˺���" << endl;
}
class Boss :public Enemy
{
public:
	Boss();
	void m_SpecialAttack()const;
	void Attack()const;
private:
	int m_DamageMultiplier;
};
Boss::Boss()
{
	m_DamageMultiplier = 3;
	cout << "\nBoss��Ĺ��캯��������" << endl;
}
void Boss::m_SpecialAttack()const
{
	cout << "Boss������⹥�����" << (m_DamageMultiplier*m_Damage) << "���˺���" << endl;
}
void Boss::Attack()const
{
	cout << "Boss��Ĺ������" << m_Damage << "���˺���" << endl;
}

int main()
{
	cout << "����Enemy����." << endl;
	Enemy enemy1;
	enemy1.Attack();
	cout << "\n����Boss����." << endl;
	Boss boss1;
	boss1.Attack();
	boss1.m_SpecialAttack();
	cout << endl;
	system("pause");
	return 0;
}
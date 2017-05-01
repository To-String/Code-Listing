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
	cout << "Enemy类的构造函数被调用" << endl;
}
void Enemy::Attack()const
{
	cout << "Enemy类的攻击造成" << m_Damage << "点伤害！" << endl;
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
	cout << "\nBoss类的构造函数被调用" << endl;
}
void Boss::m_SpecialAttack()const
{
	cout << "Boss类的特殊攻击造成" << (m_DamageMultiplier*m_Damage) << "点伤害！" << endl;
}
void Boss::Attack()const
{
	cout << "Boss类的攻击造成" << m_Damage << "点伤害！" << endl;
}

int main()
{
	cout << "创建Enemy对象." << endl;
	Enemy enemy1;
	enemy1.Attack();
	cout << "\n创建Boss对象." << endl;
	Boss boss1;
	boss1.Attack();
	boss1.m_SpecialAttack();
	cout << endl;
	system("pause");
	return 0;
}
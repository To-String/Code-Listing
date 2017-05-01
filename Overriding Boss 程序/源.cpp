#include<iostream>
using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	void virtual Taunt()const;
	void virtual Attack()const;
private:
	int m_Damage;
};
Enemy::Enemy(int damage)
{
	m_Damage = damage;
	cout << "\nEnemy类的构造函数被调用" << endl;
}
void Enemy::Taunt()const
{
	cout << "敌人说他会打死你的" << endl;
}
void Enemy::Attack()const
{
	cout << "Enemy类的Attack函数造成" << m_Damage << "点伤害.";
}

class Boss :public Enemy
{
public:
	Boss(int damage = 30);
	void virtual Taunt()const;
	void virtual Attack()const;
};
Boss::Boss(int damage):Enemy(damage)
{
	cout << "\nBoss类的构造函数被调用" << endl;
}

void Boss::Taunt()const
{
	cout << "首领说他将会结束你这可伶的存在." << endl << endl;
}
void Boss::Attack()const
{
	Enemy::Attack();
	cout << "并嘲笑你." << endl;
}

int main()
{
	cout << "Enemy 对象：";
	Enemy anEnemy;
	anEnemy.Taunt();
	anEnemy.Attack();
	cout << "\n\nBoss对象：\n";
	Boss aBoss;
	aBoss.Taunt();
	aBoss.Attack();
、
	cout << endl;
	system("pause");
	return 0;
}


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
	cout << "\nEnemy��Ĺ��캯��������" << endl;
}
void Enemy::Taunt()const
{
	cout << "����˵����������" << endl;
}
void Enemy::Attack()const
{
	cout << "Enemy���Attack�������" << m_Damage << "���˺�.";
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
	cout << "\nBoss��Ĺ��캯��������" << endl;
}

void Boss::Taunt()const
{
	cout << "����˵����������������Ĵ���." << endl << endl;
}
void Boss::Attack()const
{
	Enemy::Attack();
	cout << "����Ц��." << endl;
}

int main()
{
	cout << "Enemy ����";
	Enemy anEnemy;
	anEnemy.Taunt();
	anEnemy.Attack();
	cout << "\n\nBoss����\n";
	Boss aBoss;
	aBoss.Taunt();
	aBoss.Attack();
��
	cout << endl;
	system("pause");
	return 0;
}


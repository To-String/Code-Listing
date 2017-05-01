#include<iostream>
using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	virtual~Enemy();
	void virtual Attack()const;
protected:
	int *m_pDamage;
};
Enemy::Enemy(int damage):
	m_pDamage(new int(damage))
{
	cout << "Enemy的构造函数被调用" << "\n" << endl;
}
Enemy::~Enemy()
{
	cout << "Enemy的析构函数被调用，释放 m_pDamage." << endl;
	delete m_pDamage;
	m_pDamage = NULL;
}
void Enemy::Attack()const
{
	cout << "普通敌人的攻击造成" << (*m_pDamage) << "点伤害." << endl;
}

class Boss :public Enemy
{
public:
	Boss(int multiplier = 3);
	virtual~Boss();
	void virtual Attack()const;
protected:
	int *m_pMultiplier;
};
Boss::Boss(int multiplier)
{
	m_pMultiplier = new int(multiplier);
	cout << "Boss类的构造函数被调用" << endl;
}
Boss::~Boss()
{
	cout << "Boss的析构函数被调用，释放m_pMultiplier.\n";
	delete m_pMultiplier;
	m_pMultiplier = NULL;
}
void Boss::Attack()const
{
	cout << "Boss的攻击造成" << ((*m_pMultiplier)*(*m_pDamage)) << "点伤害" << endl;
	Enemy::Attack();  //这里会调用基类的Attack（）函数
}
int main()
{
	cout << "Enemy通过对象指针指向Boss对象，调用Attack（）函数：\n";
	Enemy *pBadGuy = new Boss;  //pBadGut是指向Boss对象的Enemy的指针
	pBadGuy->Attack();  
	cout << "\n\n释放Enemy指针：" << endl;
	delete pBadGuy;  //先释放派生类的析构函数，在释放基类的析构函数
	pBadGuy = NULL;

	cout << endl;
	system("pause");
	return 0;
}
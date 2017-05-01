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
	cout << "Enemy�Ĺ��캯��������" << "\n" << endl;
}
Enemy::~Enemy()
{
	cout << "Enemy���������������ã��ͷ� m_pDamage." << endl;
	delete m_pDamage;
	m_pDamage = NULL;
}
void Enemy::Attack()const
{
	cout << "��ͨ���˵Ĺ������" << (*m_pDamage) << "���˺�." << endl;
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
	cout << "Boss��Ĺ��캯��������" << endl;
}
Boss::~Boss()
{
	cout << "Boss���������������ã��ͷ�m_pMultiplier.\n";
	delete m_pMultiplier;
	m_pMultiplier = NULL;
}
void Boss::Attack()const
{
	cout << "Boss�Ĺ������" << ((*m_pMultiplier)*(*m_pDamage)) << "���˺�" << endl;
	Enemy::Attack();  //�������û����Attack��������
}
int main()
{
	cout << "Enemyͨ������ָ��ָ��Boss���󣬵���Attack����������\n";
	Enemy *pBadGuy = new Boss;  //pBadGut��ָ��Boss�����Enemy��ָ��
	pBadGuy->Attack();  
	cout << "\n\n�ͷ�Enemyָ�룺" << endl;
	delete pBadGuy;  //���ͷ���������������������ͷŻ������������
	pBadGuy = NULL;

	cout << endl;
	system("pause");
	return 0;
}
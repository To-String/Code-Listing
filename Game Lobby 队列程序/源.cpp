#include<iostream>
#include<string>
using namespace std;

class Player
{
public:
	Player(const string &name = "");
	string GetName()const;
	Player *GetNext()const;
	void SetNext(Player *next);

private:
	string m_Name;  //队列的数据域，
	Player *m_pNext;  //队列的指针域，指向队列的下一个节点的指针
};

Player::Player(const string &name) :
	m_Name(name),
	m_pNext(0)
{
	cout << "Player 类的构造函数将被调用" << endl << endl;
}
string Player::GetName()const
{
	return m_Name;
}
Player* Player::GetNext()const
{
	return m_pNext;
}
void Player::SetNext(Player *next)
{
	m_pNext = next;
}

//Lobby类表示大厅或者玩家等待的队列
class Lobby
{
	friend ostream &operator<<(ostream &os, const Lobby &aLobby);
public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player *m_Head;  //指向Player对象的头指针，是指向队列中的第一个节点的指针
};
Lobby::Lobby() :
	m_Head(0)  //将m_Head设置为空指针
{
	cout << "Lobby 类的构造函数将被调用" << endl << endl;
}
Lobby::~Lobby()
{
	cout << "Lobby类的析构函数被调用" << endl << endl;
	Clear();  //从列表中删除所有的Player对象，释放分配的内存
}
void Lobby::AddPlayer()
{
	cout << "请输出一个新的游戏玩家的名字：";
	string name;
	cin >> name;
	Player *pNewPlayer = new Player(name);  //创建一个新的玩家节点并且为它分配内存
	if (m_Head ==0)  //如果m_Head指针指向的位置空，那么此队列为空队列，添加的新玩家在队列的第一个节点的位置
	{
		m_Head = pNewPlayer;  //那么就把新玩家变成m_Head指针指向的第一个节点的位置
	}
	else
	{
		Player *pIter = m_Head;//把m_Head指针变成一个临时指针pIter，那么这两个指针都指向同一个位置，即指向队列的第一个节点
		while (pIter->GetNext()!= 0)  //如果pIter指针指向的后继位置不为空时 就循序，否则，执行最后一句
		{
			pIter = pIter->GetNext();  //那么就把pIter指针就往后移动一格，每次循环都是如此
		}                         //如果pIter指针指向的后继位置为空时 就退出循序
		pIter->SetNext(pNewPlayer);   //把pIter指针指向新玩家的地址，那么新玩家在队列的末尾
	}
}

void Lobby::RemovePlayer()
{
	if (m_Head == 0) //判断m_Head指针是否指向空
	{
		cout << "游戏大厅是空的，没有玩家可以删除" << endl << endl;
	}
	else
	{
		Player *pTemp = m_Head;  //创建一个临时指针pTemp跟m_Head都指向队列的第一个玩家的位置
		m_Head = m_Head->GetNext();  //然后m_Head指针往后移动一格，每次循环都是如此
		delete pTemp;   //然后把p_Temp指向的第一个玩家的位置删除释放
	}
}
void Lobby::Clear()
{
	while (m_Head != 0)  //判断m_Head指针是否指向空
	{
		RemovePlayer();  //不为空就删除都队列中的所以玩家
	}
}
ostream &operator<<(ostream &os, const Lobby &aLobby)
{
	Player *pIter = aLobby.m_Head;  //创建一个临时指针pIter跟m_Head都指向队列的第一个玩家的位置
	os << "\n是谁在游戏大厅:\n";
	if (pIter == 0)  //当pIter指针指向空时，说明没有玩家存在
	{
		os << "这个大厅是空的.\n";
	}
	else
	{
		while (pIter!=0)  //当pIter指针不指向空时，循环
		{
			os << pIter->GetName() << endl; //就输出pIter指针指向的第一个节点的玩家名字
			pIter = pIter->GetNext();  /*输出后，再把pIter指针指向的第一个节点变成pIter指针，每次循环都会往后移动一次*/
		} 
	}
	return os;
}

int main()
{
	Lobby myLobby;
	int choice;
	do
	{
		cout<<myLobby << endl;
		cout << "\n游戏大厅\n";
		cout << "0 - 退出游戏！" << endl;
		cout << "1 - 添加一个游戏玩家到游戏大厅." << endl;
		cout << "2 - 在游戏大厅中删除一个玩家." << endl;
		cout << "3 - 清除所有游戏玩家." << endl;
		cout << endl << "输出你的选择：";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "再见！" << endl;
			break;
		case 1:
			myLobby.AddPlayer();
			break;
		case 2:
			myLobby.RemovePlayer();
			break;
		case 3:
			myLobby.Clear();
			break;
		default:
			cout << "您选择的序号不正确！" << endl;
		}
	} while (choice != 0);

   system("pause");
   cout << endl;
   return 0;
}
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
	string m_Name;  //���е�������
	Player *m_pNext;  //���е�ָ����ָ����е���һ���ڵ��ָ��
};

Player::Player(const string &name) :
	m_Name(name),
	m_pNext(0)
{
	cout << "Player ��Ĺ��캯����������" << endl << endl;
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

//Lobby���ʾ����������ҵȴ��Ķ���
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
	Player *m_Head;  //ָ��Player�����ͷָ�룬��ָ������еĵ�һ���ڵ��ָ��
};
Lobby::Lobby() :
	m_Head(0)  //��m_Head����Ϊ��ָ��
{
	cout << "Lobby ��Ĺ��캯����������" << endl << endl;
}
Lobby::~Lobby()
{
	cout << "Lobby�����������������" << endl << endl;
	Clear();  //���б���ɾ�����е�Player�����ͷŷ�����ڴ�
}
void Lobby::AddPlayer()
{
	cout << "�����һ���µ���Ϸ��ҵ����֣�";
	string name;
	cin >> name;
	Player *pNewPlayer = new Player(name);  //����һ���µ���ҽڵ㲢��Ϊ�������ڴ�
	if (m_Head ==0)  //���m_Headָ��ָ���λ�ÿգ���ô�˶���Ϊ�ն��У���ӵ�������ڶ��еĵ�һ���ڵ��λ��
	{
		m_Head = pNewPlayer;  //��ô�Ͱ�����ұ��m_Headָ��ָ��ĵ�һ���ڵ��λ��
	}
	else
	{
		Player *pIter = m_Head;//��m_Headָ����һ����ʱָ��pIter����ô������ָ�붼ָ��ͬһ��λ�ã���ָ����еĵ�һ���ڵ�
		while (pIter->GetNext()!= 0)  //���pIterָ��ָ��ĺ��λ�ò�Ϊ��ʱ ��ѭ�򣬷���ִ�����һ��
		{
			pIter = pIter->GetNext();  //��ô�Ͱ�pIterָ��������ƶ�һ��ÿ��ѭ���������
		}                         //���pIterָ��ָ��ĺ��λ��Ϊ��ʱ ���˳�ѭ��
		pIter->SetNext(pNewPlayer);   //��pIterָ��ָ������ҵĵ�ַ����ô������ڶ��е�ĩβ
	}
}

void Lobby::RemovePlayer()
{
	if (m_Head == 0) //�ж�m_Headָ���Ƿ�ָ���
	{
		cout << "��Ϸ�����ǿյģ�û����ҿ���ɾ��" << endl << endl;
	}
	else
	{
		Player *pTemp = m_Head;  //����һ����ʱָ��pTemp��m_Head��ָ����еĵ�һ����ҵ�λ��
		m_Head = m_Head->GetNext();  //Ȼ��m_Headָ�������ƶ�һ��ÿ��ѭ���������
		delete pTemp;   //Ȼ���p_Tempָ��ĵ�һ����ҵ�λ��ɾ���ͷ�
	}
}
void Lobby::Clear()
{
	while (m_Head != 0)  //�ж�m_Headָ���Ƿ�ָ���
	{
		RemovePlayer();  //��Ϊ�վ�ɾ���������е��������
	}
}
ostream &operator<<(ostream &os, const Lobby &aLobby)
{
	Player *pIter = aLobby.m_Head;  //����һ����ʱָ��pIter��m_Head��ָ����еĵ�һ����ҵ�λ��
	os << "\n��˭����Ϸ����:\n";
	if (pIter == 0)  //��pIterָ��ָ���ʱ��˵��û����Ҵ���
	{
		os << "��������ǿյ�.\n";
	}
	else
	{
		while (pIter!=0)  //��pIterָ�벻ָ���ʱ��ѭ��
		{
			os << pIter->GetName() << endl; //�����pIterָ��ָ��ĵ�һ���ڵ���������
			pIter = pIter->GetNext();  /*������ٰ�pIterָ��ָ��ĵ�һ���ڵ���pIterָ�룬ÿ��ѭ�����������ƶ�һ��*/
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
		cout << "\n��Ϸ����\n";
		cout << "0 - �˳���Ϸ��" << endl;
		cout << "1 - ���һ����Ϸ��ҵ���Ϸ����." << endl;
		cout << "2 - ����Ϸ������ɾ��һ�����." << endl;
		cout << "3 - ���������Ϸ���." << endl;
		cout << endl << "������ѡ��";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "�ټ���" << endl;
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
			cout << "��ѡ�����Ų���ȷ��" << endl;
		}
	} while (choice != 0);

   system("pause");
   cout << endl;
   return 0;
}
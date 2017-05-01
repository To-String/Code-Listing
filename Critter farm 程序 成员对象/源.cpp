#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Critter
{


public:
	Critter(const string &name = "");
	string GetName()const;
	~Critter()
	{
		cout << "Critter��������������" << endl << endl;
	}
private:
	string m_Name;
};
Critter::Critter(const string &name) :
	m_Name(name)
{
	cout << "Critter �Ĺ��캯��������" << endl << endl;
}

inline string Critter::GetName()const
{
	return m_Name;
}

class Farm
{
public:
	Farm(int space = 1);
	void Add(const Critter &aCritter);
	void RollCall()const;
	virtual~Farm()
	{
		cout << "Farm����������������" << endl << endl;
	}
private:
	vector<Critter>m_Critters;
};

Farm::Farm(int space)
{
	cout << "Farm�Ĺ��캯��������" << endl << endl;
	m_Critters.reserve(space);
}
void Farm::Add(const Critter &aCritter)
{
	m_Critters.push_back(aCritter);
}
void Farm::RollCall()const
{
	for (vector<Critter>::const_iterator iter = m_Critters.begin(); iter != m_Critters.end(); ++iter)
	{
		cout << iter->GetName() << " here.\n";
	}
}
int main()
{
	Critter *crit = new Critter("poochie");
	cout << "�ҵĶ�������ֽУ�" << crit->GetName() << endl;
	cout << "\n��������ũ��.\n";
	Farm *myFarm = new Farm(3);
	cout << "\n��ũ��������������������.\n";
	myFarm->Add(Critter("Moe"));
	myFarm->Add(Critter("Larry"));
	myFarm->Add(Critter("Curly"));
	cout << "\n��Щ������.\n";
	myFarm->RollCall();
	cout << endl;
	cout << "�ͷ��ڴ�" << endl;
	delete crit;
	delete myFarm;

	cout << endl;
	system("pause");
	return 0;
}


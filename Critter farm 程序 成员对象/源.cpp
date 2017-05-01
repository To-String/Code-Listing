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
		cout << "Critter析构函数被调用" << endl << endl;
	}
private:
	string m_Name;
};
Critter::Critter(const string &name) :
	m_Name(name)
{
	cout << "Critter 的构造函数被调用" << endl << endl;
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
		cout << "Farm的析构函数被调用" << endl << endl;
	}
private:
	vector<Critter>m_Critters;
};

Farm::Farm(int space)
{
	cout << "Farm的构造函数被调用" << endl << endl;
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
	cout << "我的动物的名字叫：" << crit->GetName() << endl;
	cout << "\n创建动物农场.\n";
	Farm *myFarm = new Farm(3);
	cout << "\n在农场中添加三个动物的名字.\n";
	myFarm->Add(Critter("Moe"));
	myFarm->Add(Critter("Larry"));
	myFarm->Add(Critter("Curly"));
	cout << "\n这些动物在.\n";
	myFarm->RollCall();
	cout << endl;
	cout << "释放内存" << endl;
	delete crit;
	delete myFarm;

	cout << endl;
	system("pause");
	return 0;
}


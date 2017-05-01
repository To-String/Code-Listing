#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Critter
{
public:
	Critter(const string &name = "",int age=0);
	~Critter();
	Critter(const Critter &c);
	Critter &Critter::operator=(const Critter &c);
	void Greet();

private:
	string *m_pName;
	int m_Age;
};

Critter::Critter(const string &name,int age)
{
	cout << "Critter类的构造函数被调用" << endl << endl;
	m_pName = new string(name);
	m_Age = age;
}
Critter::~Critter()
{
	cout << "Critter 类的析构函数被调用" << endl << endl;
	delete m_pName;
}
Critter::Critter(const Critter &c)
{
	cout << "Critter的拷贝构造函数被调用" << endl << endl;
	m_pName = new string(*(c.m_pName));
	m_Age = c.m_Age;
}

Critter &Critter::operator=(const Critter &c)
{
	cout << "Critter 类的重载赋值运算符函数被调用" << endl << endl;
	delete m_pName;
	if (this != &c)
	{
		m_pName = new string(*(c.m_pName));
		m_Age = c.m_Age;
	}
	return *this;
}

void Critter::Greet()
{
	cout << "我是" <<*m_pName<< "和我的年龄是:" << m_Age << "." << endl;
	cout << "&m_pName:" << &m_pName << endl;
}

void testDestructor()
{
	Critter toDestroy("Rover", 3);
	toDestroy.Greet();
}

void testCopyConstructor(Critter aCopy)
{
	aCopy.Greet();
}
void testAssignmentOp()
{
	Critter crit1("crit1", 7);
	Critter crit2("crit2", 9);
	crit1 = crit2;

	crit1.Greet();
	crit2.Greet();

	Critter crit3("crit", 11);
	crit3 = crit3;
	crit3.Greet();

}

int main()
{
	testDestructor();
	cout << endl;

	Critter crit("Poochie", 5);
	crit.Greet();

	testCopyConstructor(crit);
	crit.Greet();
	cout << endl;
	testAssignmentOp();
	
	system("pause");
	cout << endl;
	return 0;
}
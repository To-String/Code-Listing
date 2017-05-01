#include<iostream>
#include<string>
using namespace std;

class Critter
{
	friend void peek(const Critter &aCritter);
	friend ostream &operator<<(ostream &os, const Critter &aCritter);
public:
	Critter(const string &name = "");
private:
	int a = 10;
	string m_Name;
	
};
Critter::Critter(const string &name)
{
	m_Name =name;
}
void peek(const Critter &aCritter)
{
	cout << aCritter.m_Name << endl;
}
ostream &operator<<(ostream &os, const Critter &aCritter)
{
	os << "Critter object - m_Name: " << aCritter.m_Name << " " << aCritter.a << endl;
	return os;
}

int main()
{
	Critter crit("poochie");
	cout << "调用 peek()函数来访问私有成员m_Name:\n";
	peek(crit);
	cout << "用<<运算符将对象输出：" << crit<< endl;
	cout << endl;
	system("pause");
	return 0;
}
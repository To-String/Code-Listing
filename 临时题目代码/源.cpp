#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(int r = 0,int i=0);
	friend Complex operator+(Complex &m, Complex &s);   //两对象相加，友元
	friend Complex operator-(Complex &m, Complex &s);

	Complex operator+(Complex &m);  //相减，  成员
	Complex operator-(Complex &s);

	friend Complex operator+(Complex &i, int b);   //对象与整型数相加，友元
	friend Complex operator-(Complex &i, int b);  //相减，友元

	Complex operator+(const int b); //对象与整型数相加，成员函数
	Complex operator-(const int c);  //对象与整型数相减，成员函数



	void display();
private:
	int m_real;
	int m_img;
};
Complex::Complex(int r, int i)
{
	m_real = r;
	m_img = i;
}
Complex operator+(Complex &m, Complex &s)
{
	return Complex(m.m_real + s.m_real, m.m_img + s.m_img);
}
Complex operator-(Complex &m, Complex &s)
{
	return Complex(m.m_real - s.m_real, m.m_img - s.m_img);
}
Complex Complex::operator+(Complex &m)
{
	return Complex(m_real + m.m_real, m_img + m.m_img);
}
Complex Complex::operator-(Complex &s)
{
	return Complex(m_real - s.m_real, m_img - s.m_img);
}

void Complex::display()
{
	cout << "输出m_real：" << m_real << " 输出m_img：" << m_img << "\n" << endl;
}

Complex operator+(Complex &i, int b)   //对象与整型数相加，友元
{
	return Complex(i.m_real + b, i.m_img + b);
}
Complex operator-(Complex &i, int b)  //相减，友元
{
	return Complex(i.m_real - b, i.m_img - b);
}
Complex Complex::operator+(const int b) //对象与整型数相加，成员函数
{
	return Complex(m_real + b, m_img + b);
}
Complex Complex::operator-(const int c)  //对象与整型数相减，成员函数
{
	return Complex(m_real - c, m_img - c);
}
int main()
{
	Complex c1(2, 3);
	Complex c2(5, 4);
	Complex c3;

	c3 = operator+(c1, c2);  //两对象的加法
	c3.display();

	c3 = operator-(c1, c2);  //减法
	c3.display();

	c3 = c1.operator+(c2);  //调用成员函数
	c3.display();

	c3 = c1.operator-(c2);
	c3.display();

	cout << "********************************************************************" << "\n" << endl;

	c3 = operator+(c1, 10);   //对象与实数的加减法,调用的友元
	c3.display();

	c3 = operator-(c1, 10);
	c3.display();

	c3 = c1.operator+(10);  //对象与实数的加减法，  调用成员函数
	c3.display();

	c3 = c1.operator-(10);
	c3.display();
	cout << endl;
	system("pause");
	return 0;
}
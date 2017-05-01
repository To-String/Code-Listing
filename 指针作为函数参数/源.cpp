#include<iostream>
using namespace std;

void badSwap(int x, int y);
void goodSwap(int *const px, int *const py);

int main()
{
	int myScore = 150;
	int yourScore = 1000;
	int &a = myScore;
	int &b = yourScore;

	int *c = &myScore;
	int *d = &yourScore;
	cout << "初始值分别为：" << endl;
	cout << "myScore:" << myScore << endl;
	cout << "yourScre:" << yourScore << endl << endl;

	cout << "调用 badSwap()\n";
	badSwap(myScore, yourScore);
	cout << "myScore:" << myScore << endl;
	cout << "yourScre:" << yourScore << endl << endl;

	cout << "调用 goodSwap()\n";
	goodSwap(c, d);  //实参也可以使用 &a和&b，  也可以达到同样的效果
	cout << "myScore:" << myScore << endl;
	cout << "yourScre:" << yourScore << endl << endl;
	system("pause");
	return 0;
}
void badSwap(int x, int y)
{
	int temp=x;
	x = y;
	y = temp;
}
void goodSwap(int *const px, int *const py)

{
	int temp = *px;
	*px = *py;
	*py = temp;
}
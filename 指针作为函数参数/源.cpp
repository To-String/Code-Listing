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
	cout << "��ʼֵ�ֱ�Ϊ��" << endl;
	cout << "myScore:" << myScore << endl;
	cout << "yourScre:" << yourScore << endl << endl;

	cout << "���� badSwap()\n";
	badSwap(myScore, yourScore);
	cout << "myScore:" << myScore << endl;
	cout << "yourScre:" << yourScore << endl << endl;

	cout << "���� goodSwap()\n";
	goodSwap(c, d);  //ʵ��Ҳ����ʹ�� &a��&b��  Ҳ���Դﵽͬ����Ч��
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
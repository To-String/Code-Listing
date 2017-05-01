#include<iostream>
using namespace std;

int *intOnHeap();
void leak1();
void leak2();

int main()
{
	int *pHeap = new int(10);
	cout << "*pHeap:" << *pHeap << endl << endl;

	int *pHeap2 = intOnHeap();
	cout << "*pHeap:" << *pHeap2 << endl << endl;

	cout << "释放pHeap的内存.\n\n";
	delete pHeap;

	cout << "释放pHeap2的内存.\n\n";
	delete pHeap2;

	pHeap = NULL;
	pHeap2 = NULL;
	cout << endl;
	system("pause");
	return 0;
}
int *intOnHeap()
{
	int *Temp = new int(20);
	return Temp;
}
void leak1()
{
	int *drip1 = new int(30);
}
void leak2()
{
	int *drip2 = new int(50);
	drip2 = new int(100);
	delete drip2;
}
#include<iostream>
using namespace std;

void increase(int *const array, const int NUM_ELEMENTS);
void display(const int *const array, const int NUM_ELEMENTS);
int main()
{
	cout << "����һ���߷�����.\n\n";
	const int NUM_SCORES = 3;
	int highScores[NUM_SCORES] = { 5000,3500,2700 };
	cout << "ʹ����������Ϊָ�볣������ʾ����.\n";
	cout << *highScores << endl;
	cout << *(highScores + 1) << endl;
	cout << *(highScores + 2) << endl << endl;

	cout << "ͨ������������Ϊָ�볣�����ı����.\n\n";
	increase(highScores, NUM_SCORES);
	cout << "ͨ����������Ϊ������ָ�볣������ʾ����.\n";
	display(highScores, NUM_SCORES);
	cout << endl;
	system("pause");
	return 0;
}
void increase(int *const array, const int NUM_ELEMENTS)
{
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		array[i] += 500;
	}
}
void display(const int *const array, const int NUM_ELEMENTS)
{
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		cout << array[i] << endl;
	}
}
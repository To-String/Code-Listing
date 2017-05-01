#include<iostream>
using namespace std;

void increase(int *const array, const int NUM_ELEMENTS);
void display(const int *const array, const int NUM_ELEMENTS);
int main()
{
	cout << "创建一个高分数组.\n\n";
	const int NUM_SCORES = 3;
	int highScores[NUM_SCORES] = { 5000,3500,2700 };
	cout << "使用数组名作为指针常量来显示分数.\n";
	cout << *highScores << endl;
	cout << *(highScores + 1) << endl;
	cout << *(highScores + 2) << endl << endl;

	cout << "通过将数组名作为指针常量来改变分数.\n\n";
	increase(highScores, NUM_SCORES);
	cout << "通过将数组作为常量的指针常量来显示分数.\n";
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
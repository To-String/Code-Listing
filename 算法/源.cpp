#include<iostream>
using namespace std;
#define TT_ERROR -1
int binary_search(int arr[], int left, int right, int key)
{
	if (right < left)
	{
		return TT_ERROR;
	}
		
	int mid = left + ((right - left) >> 1);

		if (arr[mid] > key)
		{
			return binary_search(arr, left, mid - 1, key);
		}
		else if (arr[mid] < key)
		{
			return binary_search(arr, mid + 1, right, key);
		}
		else
		{
			return mid;
		}
		return TT_ERROR;
}

int main()
{
	while (true)
	{
		{
			cout << "\n************************欢迎来到来到二分查找的世界！**********************\n" << endl
				<< "输入0，退出程序！" << endl
				<< "输入1，进行二分查找！" << endl
				<< "输入2，清屏！" << endl;
		}
		cout << "\n请输入你的选择：";
		int choice(0);
		cin >> choice;
		if (choice == 0)
		{
			cout << "程序已退出！" << endl;
			break;
		}
		switch (choice)
		{
		case 1:
		{
			cout << "请输入你想要查找元素列表的长度：";
			int list_Length(0);
			cin >> list_Length;

			int *array = new int[list_Length];

			for (int i = 0; i < list_Length; ++i)
			{
				cin >> array[i];
			}
			int left(0);   //数组的首位置，即data[0]处
			int right = list_Length - 1;   //数组的最后一个位置，即data[n-1],数组大小为list_Length
			int element(0), locate(0);
			cout << "请输入你想要在数组中查找的元素是：";
			cin >> element;
			if ((locate = binary_search(array, left, right, element)) >= 0)
			{
				cout << "找到元素" << element << ",它在数组中的位置为：" << locate << endl;
			}
			else
			{
				cout << "没有找到你想要查找的元素" << element << "!" << endl;
			}
			delete[]array;
			array = nullptr;
			break;
		}
		case 2:
			system("cls");
			cout << "屏幕已清屏，可以重新输入！" << endl;
			break;
		default:
			cout << "序号输入错误，请重新输入！" << endl;
		}
	}
	system("pause");
	return 0;
}

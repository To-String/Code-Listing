#include<iostream>
using namespace std;
#define TT_ERROR -1
int binary_search(int arr[], int array_size, int key)
{
	if ((arr == nullptr) || (array_size == 0))
	{
		return TT_ERROR;
	}
	int left(0);   //数组的首位置，即data[0]处
	int right = array_size - 1;   //数组的最后一个位置，即data[n-1],数组大小为array_size
	while (left <= right)
	{
		//int mid = (left + right) / 2;//array_size为偶数，取靠左的那个(当left和right比较大时，二者之和可能会溢出)  
		int mid = left + ((right - left) >> 1);/*此处的mid的计算一定要放在while循环内部，
											   否则mid无法正确更新;并且此处用移位代替除以2可以提高效率，
								   而且可以防止溢出。*/
		if (arr[mid] > key)
		{
			right = mid - 1; 
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
		
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
			;
			int element(0), locate(0);
			cout << "请输入你想要在数组中查找的元素是：";
			cin >> element;
			if ((locate = binary_search(array, list_Length, element))>= 0)
			{
				cout << "找到元素" << element << ",它在数组中的位置为：" << locate << endl;
			}
			else
				cout << "没有找到你想要查找的元素" << element << "!" << endl;
				
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

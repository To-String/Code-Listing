#include<iostream>
using namespace std;
#define TT_ERROR -1
int binary_search(int arr[], int array_size, int key)
{
	if ((arr == nullptr) || (array_size == 0))
	{
		return TT_ERROR;
	}
	int left(0);   //�������λ�ã���data[0]��
	int right = array_size - 1;   //��������һ��λ�ã���data[n-1],�����СΪarray_size
	while (left <= right)
	{
		//int mid = (left + right) / 2;//array_sizeΪż����ȡ������Ǹ�(��left��right�Ƚϴ�ʱ������֮�Ϳ��ܻ����)  
		int mid = left + ((right - left) >> 1);/*�˴���mid�ļ���һ��Ҫ����whileѭ���ڲ���
											   ����mid�޷���ȷ����;���Ҵ˴�����λ�������2�������Ч�ʣ�
								   ���ҿ��Է�ֹ�����*/
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
			cout << "\n************************��ӭ�����������ֲ��ҵ����磡**********************\n" << endl
			    << "����0���˳�����" << endl
			    << "����1�����ж��ֲ��ң�" << endl
				<< "����2��������" << endl;
		}
		cout << "\n���������ѡ��";
		int choice(0);
		cin >> choice;
		if (choice == 0)
		{
			cout << "�������˳���" << endl;
			break;
		}
		switch (choice)
		{
		case 1:
		{
			cout << "����������Ҫ����Ԫ���б�ĳ��ȣ�";
			int list_Length(0);
			cin >> list_Length;

			int *array = new int[list_Length];

			for (int i = 0; i < list_Length; ++i)
			{
				cin >> array[i];
			}
			;
			int element(0), locate(0);
			cout << "����������Ҫ�������в��ҵ�Ԫ���ǣ�";
			cin >> element;
			if ((locate = binary_search(array, list_Length, element))>= 0)
			{
				cout << "�ҵ�Ԫ��" << element << ",���������е�λ��Ϊ��" << locate << endl;
			}
			else
				cout << "û���ҵ�����Ҫ���ҵ�Ԫ��" << element << "!" << endl;
				
			delete[]array;
			array = nullptr;
			break;
		}
		case 2:
			system("cls");
			cout << "��Ļ�������������������룡" << endl;
			break;
		default:
			cout << "�������������������룡" << endl;
		}
	}
	system("pause");
	return 0;
}

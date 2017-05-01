#include<iostream>
using namespace std;
#define true 1
#define false 0
typedef int ElemType;
typedef  int Status;
#define MAXSIZE 100   //�洢�ռ��ʼ������
class sqList
{
public:
	unsigned int ListLength()const; //������Ա��еĸ���
	bool InitList(); //��ʼ�����Ա�
	bool ListEmpty();  //�ж����Ա��Ƿ�Ϊ��

	Status LocateElem(const ElemType e); //���Ա��в�����e��ȵ�Ԫ�أ����ص�һ����e���Ԫ�������Ա��е��±꣬���򣬷���0
	void ClearList(); //�����Ա����
	bool DestroyList();//�������Ա�  

	Status GetElem(int i, ElemType &e);   //�����Ա��в��ҵ�i��Ԫ��
	Status ListInsert(int i, ElemType e); //�����Ա��е�i��λ�ò���ֵΪe��Ԫ��
	Status ListDelete(int i, ElemType &e);// ɾ��������ɾ�����Ա��е�i��Ԫ��

private:
	ElemType *data;  //���Ա��е�����Ԫ�أ����洢��λ�þ��Ǵ洢�ռ�Ĵ洢λ��
	ElemType length;   //���Ա�ǰ����

};


bool sqList::DestroyList()  //���Ա�ݻ�
{
	delete[]data;
	data = NULL;
	if (!data)
	{
		cout << "���Ա��Ѵݻ�" << endl;
		return true;
	}
	else
		cout << "���Ա�û�дݻ�" << endl;
	return false;
}
inline unsigned int sqList::ListLength()const   //���������Ա��еĸ���
{
	return length;
}
bool sqList::ListEmpty()  //�жϵ������Ա��Ƿ�Ϊ�գ�
{
	if (length == 0)
		return true;
	return false;
}
Status sqList::LocateElem(const ElemType e)       /*���Ա��в�����e��ȵ�Ԫ�أ����ص�һ����e���Ԫ�������Ա��е���ţ������ص�
											   ���±�Ϳ��Բ���+1*/
{
	for (int i = 0; i <length; ++i)
	{
		if (*(data + i) == e)  //�������Ա�����û�и�e��ȵ�Ԫ��
			return i + 1;    /*��e��ȵ�Ԫ�ط��أ���Ϊ���Ա��Ǵ�1��ʼ�ģ�������±���0��ʼ�ģ��������Ա��i��Ԫ�ش洢��
							   �����±�i-1��λ�ã����ص�ʱ��Ҫ��1*/
	}
	return 0;

}
void sqList::ClearList()   //�����Ա��Ԫ�����
{
	delete data;
	data = NULL; 
	length = 0;
}
//��ʼ�����Ա�, ��ʼ�����Ա�����ʹ�ù��캯����ʼ��
bool sqList::InitList()
{
	data = new ElemType[MAXSIZE];   //��Ϊ���Ա����ռ�
	if (!data) //�ж�p�Ƿ���䵽�ڴ棬    ��û�У� �򷵻ش���
	{
		cout << "û�з��䵽�ڴ棬����·��䣡" << endl;
		return false;
	}
	length =0;         //���Ա�ǰ��ʼ��Ϊ0
	cout << "��ʼ�������Ա�ĳ���Ϊ��" << length << endl;
	return true;
}
//���Ԫ�صĲ���,�����Ա��е�i��λ�õ�Ԫ�ص�ֵ���ظ�e
Status sqList::GetElem(int i, ElemType &e)
{
	if (length == 0 || i<1 || i>length)  //�жϵ�ǰ���Ա���ΪΪ�ա�����i����ͷ��ش���
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
	e = *(data + i - 1); //�ѵ�i��Ԫ�ط��ظ�e
	return true;
}
//����Ԫ�أ�  �����Ա��е�i��λ��֮ǰ������Ԫ��e
Status sqList::ListInsert(int i, ElemType e)
{
	int k;    //һ����ʱ������������Ϊ����forѭ���ĵ�������.
	if (length == MAXSIZE) //���Ա�����
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
		
	if (i<1 || i>length + 1)     //��i���ڷ�Χ�洦��ʱ��
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
	if (i <= length)    //����������ݲ��ڱ�β,���ڱ�βֱ������if���
	{
		for (k = length; k >= i; k--)  /*Ԫ��i��������Ԫ�ض�������һ�����ڳ�i���Ŀռ���Ҫ�����Ԫ��,*/
			*(data + k) = *(data +k-1);  //����data[k-1]��  ���ǰ�k-1��Ԫ�ر��k��Ԫ�أ��൱������ƶ�
	}
	*(data + i - 1) = e;  //����Ԫ�ز���
	length++;    //����1
	return true;
}

//ɾ��Ԫ�����Ա��е�i������Ԫ�أ�����e������ֵ�� ����һ
Status sqList::ListDelete(int i, ElemType &e)
{
	int k;   //һ����ʱ������������Ϊ����forѭ���ĵ�������.
	if (length == 0)     //���Ա�Ϊ��ʱ
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
	if (i<1 || i>length)       //ɾ����λ�ò���ȷ
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
	e = *(data + i - 1);   //ȡ��Ҫɾ����Ԫ��
	if (i<length)     //���Ҫɾ���Ĳ������λ��
	{
		for (k = i; k<length; k++)     //��ɾ��λ�ú��Ԫ����ǰ�ƶ���  Ҫɾ����λ�ò��ܴ��ڱ�
			*(data + k-1) = *(data + k);  
	}
	length--;    //����һ
	return true;
}
int main()
{
	sqList sq1;
	sq1.InitList();   //��ʼ�����Ա�
	sq1.ListInsert(1, 5);
	sq1.ListInsert(2, 8);
	sq1.ListInsert(3, 2);
	sq1.ListInsert(4, 6);
	sq1.ListInsert(5, 15);
	sq1.ListInsert(6, 10);
	sq1.ListInsert(6, 2);
	cout << "����ֵ�󣬱�ĵ�ǰ����Ϊ��" << sq1.ListLength() << "\n\n";

	for (int i = 0; i < sq1.ListLength(); ++i)
	{
		int e=0; //��ʾҪ�����Ԫ��
		sq1.GetElem(i + 1, e);
		cout << "���е�" << (i + 1) << "��Ԫ��Ϊ" << e << "\n";
	}
	cout << endl;
	//ɾ������
	int deleteLocation = 0;
	cout << "������Ҫɾ����Ԫ�ص�λ�ã�";
	cin >> deleteLocation;    //Ҫɾ����λ��
	int deleteElement = 0;   //Ҫɾ����Ԫ��
	sq1.ListDelete(deleteLocation, deleteElement);
	cout << "ɾ���˱��е�" << deleteLocation << "��Ԫ�أ���Ԫ��Ϊ��" << deleteElement << "\n\n";
	
	//���ɾ������е�����
	for (int i = 0; i < sq1.ListLength(); ++i)
	{
		int e(0);
		sq1.GetElem(i + 1, e);
		cout << "ɾ����ı��е�" << (i + 1) << "��Ԫ��Ϊ" << e << "\n";
	}
	cout << endl;
	//���ұ��е�����
	int searchElement=0;
	cout << "������Ҫ���ҵ�Ԫ�ص�ֵ��";
	cin >> searchElement;
	cout << endl;
	int searchLocation = sq1.LocateElem(searchElement);
	if (!searchLocation)
	{
		cout << "��ǰ�����޴�Ԫ��" << endl;
	}
	else
		cout << "��Ҫ���ҵ�Ԫ��λ�ڱ��е�" << searchLocation << "��λ��" << endl;
	cout << endl;

	//��ձ�
	sq1.ClearList();
	//�жϱ��Ƿ�Ϊ��
	if (sq1.ListEmpty())
	{
		cout << "��ǰ��Ϊ�ձ�" << endl;
	}
	else
		cout << "��ǰ��ǿգ�" << endl;
	cout << endl;
	//��������
	sq1.DestroyList();

	cout << endl;
	system("pause");
	return 0;
}
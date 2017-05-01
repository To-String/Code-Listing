#include<iostream>
#include<cassert>
using namespace std;
typedef size_t IndexType; /// ���Ƕ����±�Ϊsize_t
typedef int ElemType;

/// ͨ�����ǵ�������һ����ĸ���Ǵ�д,���������ͳ�Ա��������һ����ĸ��Сд
class SeqList
{
public:
	///����԰���������Ϊ�������ݽ�ȥ����������MAXSIZE=100��"д��"
	SeqList(size_t maxSize);
	~SeqList();
	size_t getLength() const; 
	bool isEmpty() const; 
						   /// �����������Ӧ�ý� ��ȡ�±������Ұ����LocateElem�ĳ�getIndex
	IndexType getIndex(const ElemType e) const; 
	void clear(); //�����Ա����
	bool getAt(IndexType i, ElemType& elemOut) const;   //�����Ա��в��ҵ�i��Ԫ��
	bool insertAt(IndexType i, ElemType  e); //�����Ա��е�i��λ�ò���ֵΪe��Ԫ��
											
	bool removeAt(IndexType i, ElemType& elemOut);// ɾ��������ɾ�����Ա��е�i��Ԫ��
private:
	ElemType* m_data;  //���Ա��е�����Ԫ�أ����洢��λ�þ��Ǵ洢�ռ�Ĵ洢λ��
	size_t    m_length;//���Ա�ǰ����
	size_t    m_maxSize;
};
inline size_t SeqList::getLength()const   //���������Ա��еĸ���
{
	return m_length;
}
inline bool SeqList::isEmpty() const
{
	return m_length == 0; ///����ʹ��һ�����Ϳ����ˣ�����д���������
}
//����ͨ��ʹ�ù��캯���г�ʼ���������ݳ�Ա
SeqList::SeqList(size_t maxSize)
	: m_length(0)
	, m_maxSize(m_maxSize)
	, m_data(new ElemType[maxSize])
{
	assert(maxSize > 0);//Ȼ��ʹ�ö�������һЩ�������
	cout << "�������Ա�,����: " << maxSize << endl;
}
SeqList::~SeqList()
{
	delete[] m_data;//ע��: C++����new��һ���ڴ����Ҫdelete������ڴ棬����ᵼ�������"�ڴ�й©"
	cout << "���Ա��Ѵݻ�" << endl;
}
IndexType SeqList::getIndex(const ElemType e) const      /*���Ա��в�����e��ȵ�Ԫ�أ����ص�һ����e���Ԫ�������Ա��е���ţ������ص�
														 ���±�Ϳ��Բ���+1*/
{
	for (int i = 0; i < m_length; ++i)
	{
		if (*(m_data + i) == e)  //�������Ա�����û�и�e��ȵ�Ԫ��
			return i + 1;    /*��e��ȵ�Ԫ�ط��أ���Ϊ���Ա��Ǵ�1��ʼ�ģ�������±���0��ʼ�ģ��������Ա��i��Ԫ�ش洢��
							 �����±�i-1��λ�ã����ص�ʱ��Ҫ��1*/
	}
	return 0;

}
void SeqList::clear()   //�����Ա��Ԫ�����
{
	//m_data = NULL; //�ڴ治���ͷ�,ֻҪ����lengthΪ0�Ϳ�����
	m_length = 0;
}
//���Ԫ�صĲ���,�����Ա��е�i��λ�õ�Ԫ�ص�ֵ���ظ�e
bool SeqList::getAt(IndexType i, ElemType& elemOut)const
{
	if (m_length == 0 || i<1 || i>m_length)  //�жϵ�ǰ���Ա���ΪΪ�ա�����i����ͷ��ش���
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
	elemOut = *(m_data + i - 1); //�ѵ�i��Ԫ�ط��ظ�e
	return true;
}
//����Ԫ�أ�  �����Ա��е�i��λ��֮ǰ������Ԫ��e
bool SeqList::insertAt(IndexType i, ElemType e)
{
	if (m_length == m_maxSize) //���Ա�����
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}

	if (i<1 || i>m_length + 1)     //��i���ڷ�Χ�洦��ʱ��
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
	if (i <= m_length)    //����������ݲ��ڱ�β,���ڱ�βֱ������if���
	{
		for (int k = m_length; k >= i; k--)  /*Ԫ��i��������Ԫ�ض�������һ�����ڳ�i���Ŀռ���Ҫ�����Ԫ��,*/
			*(m_data + k) = *(m_data + k - 1);  //����data[k-1]��  ���ǰ�k-1��Ԫ�ر��k��Ԫ�أ��൱������ƶ�
	}
	*(m_data + i - 1) = e;  //����Ԫ�ز���
	m_length++;    //����1
	return true;
}

//ɾ��Ԫ�����Ա��е�i������Ԫ�أ�����e������ֵ�� ����һ
bool SeqList::removeAt(IndexType i, ElemType& elemOut)
{
	if (m_length == 0)     //���Ա�Ϊ��ʱ
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
	if (i<1 || i>m_length)       //ɾ����λ�ò���ȷ
	{
		cout << "���󣬲���λ�÷Ƿ���" << endl;
		return false;
	}
	elemOut = *(m_data + i - 1);   //ȡ��Ҫɾ����Ԫ��
	if (i<m_length)     //���Ҫɾ���Ĳ������λ��
	{
		for (int k = i; k<m_length; k++)     //��ɾ��λ�ú��Ԫ����ǰ�ƶ���  Ҫɾ����λ�ò��ܴ��ڱ�
			*(m_data + k - 1) = *(m_data + k);
	}
	m_length--;    //����һ
	return true;
}

/// �������SeqList
void TestSeqList()
{
	SeqList sq1(100);
	{/// �����ƵĴ��������ͬһ�߼����û����������������ͷ����Ķ����ṹ������.
		sq1.insertAt(1, 5);
		sq1.insertAt(2, 8);
		sq1.insertAt(3, 2);
		sq1.insertAt(4, 6);
		sq1.insertAt(5, 15);
		sq1.insertAt(6, 10);
		sq1.insertAt(6, 2);
	}
	cout << "����ֵ�󣬱�ĵ�ǰ����Ϊ��" << sq1.getLength() << "\n\n";

	for (int i = 0; i < sq1.getLength(); ++i)
	{
		int e = 0; //��ʾҪ�����Ԫ��
		sq1.getAt(i + 1, e);
		cout << "���е�" << (i + 1) << "��Ԫ��Ϊ" << e << "\n";
	}
	cout << endl;

	//ɾ������
	{
		int IndexType, deleteLocation = 0;
		cout << "������Ҫɾ����Ԫ�ص�λ�ã�";
		cin >> deleteLocation;    //Ҫɾ����λ��
		int ElemType, deleteElement = 0;   //Ҫɾ����Ԫ��
		sq1.removeAt(deleteLocation, deleteElement);
		cout << "ɾ���˱��е�" << deleteLocation << "��Ԫ�أ���Ԫ��Ϊ��" << deleteElement << "\n\n";
	}
	//���ɾ������е�����
	for (IndexType i = 0; i < sq1.getLength(); ++i)
	{
		int ElemType, e(0);
		sq1.getAt(i + 1, e);
		cout << "ɾ����ı��е�" << (i + 1) << "��Ԫ��Ϊ" << e << "\n";
	}
	cout << endl;

	//���ұ��е�����
	{
		int ElemType, searchElement = 0;
		cout << "������Ҫ���ҵ�Ԫ�ص�ֵ��";
		cin >> searchElement;
		cout << endl;
		int IndexType, searchLocation = sq1.getIndex(searchElement);
		if (!searchLocation)
			cout << "��ǰ�����޴�Ԫ��" << endl;
		else
			cout << "��Ҫ���ҵ�Ԫ��λ�ڱ��е�" << searchLocation << "��λ��" << endl;
	}
	cout << endl;

	//��ձ�
	{
		sq1.clear();
		//�жϱ��Ƿ�Ϊ��
		if (sq1.isEmpty())
			cout << "��ǰ��Ϊ�ձ�" << endl;
		else
			cout << "��ǰ��ǿգ�" << endl;
	}

	cout << endl;
}
int main()
{
	TestSeqList();
	system("pause");
	return 0;
}
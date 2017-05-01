#include <iostream>
using namespace std;

#define ERROR 1
#define OK 0
typedef bool Status;
typedef int ElemType;

//���嵥������
class ChainList
{
public:
	//������
	struct Node
	{
		ElemType m_data;     //������
		Node *m_next;   //ָ����
	};
public:
	ChainList();  //���캯��������ʼ���������
	~ChainList();  //�������������ͷ��ڴ�
	void creatList(ElemType *datas, ElemType length);//��������Ϊlength����������ͨ������ָ�����������β�巨
	Status listEmpty();//�ж��Ƿ�Ϊ�ձ�

	void clearList();//  ��յ����������
	Status getElemAt(ElemType location, ElemType &elemOut);//��ȡԪ��
	Status locateElemAt(ElemType &location, ElemType element);//�������Ԫ�ص�����λ��

	Status listInsertAt(ElemType location, ElemType element);//����Ԫ��
	Status listRemoveAt(ElemType location, ElemType &elemOut);//ɾ��Ԫ��
	ElemType listLength()const;//�������Ա�ĳ���
private:
	Node *m_heap;//ͷ���
};

//ʵ����chainList�и���Ա����
ChainList::ChainList()
{
	m_heap = new Node;//��ָ������ڴ�
	m_heap->m_next = NULL;
	m_heap->m_data = 0;
}

ChainList::~ChainList()
{
	delete m_heap;
}

void ChainList::creatList(ElemType *datas, ElemType length)  //��������Ϊlength����������ͨ������ָ�����������β�巨
{
	m_heap->m_data = length;  //ͷ����е����ݴ洢��
	Node *m = m_heap;   //��ͷ�����m
	for (int i = 0; i < length; i++)  //�� i��û�г���������ĳ��Ⱦ�ѭ������
	{
		Node *n = new Node; //Ϊÿ���½ڵ����ռ� 
		n->m_data = datas[i];  //��ÿ�������ֵ�洢����Ӧ�Ľڵ�

		m->m_next = n;  //���½ڵ�n���ͷ���m�ĺ�̽ڵ㣨����β�ն˽ڵ��ָ��ָ���½ڵ㣩
		m =n;  // �ְ�ͷ���ĺ�̽ڵ���m(����˵�ǵ�һ���ڵ㣬���ǻ�����ѭ�����䶯��)
	}
	m->m_next = NULL;   //��ʾ��ǰ�������

}

Status ChainList::listEmpty()   //�ж��Ƿ�Ϊ�ձ�
{
	return (m_heap->m_data == 0 && m_heap->m_next == NULL);
}

void ChainList::clearList()    //�������
{
	Node *m = m_heap->m_next;  //��ͷ�ڵ�ĺ�̽ڵ���m
	while (m != NULL)   //�����нڵ����ʱ����ѭ������
	{
		Node *n = m->m_next;  //Ȼ���m�ĺ�̽ڵ���n
		delete m;   //ɾ����һ���ڵ㣬ÿѭ��һ�ζ�ɾ����һ���ڵ�
		m = n;  //Ȼ���n���m�� n�ͱ���˵�һ���ڵ�
	}
	m_heap->m_next = NULL;   //ͷ���ָ��ĵ�һ��������
	m_heap->m_data = 0;      //ͷ����¼���ȣ�����
}

Status ChainList::getElemAt(ElemType location, ElemType &elemOut)  //���Ԫ�صĲ���,�����Ա��е�location��λ�õ�Ԫ�ص�ֵ���ظ�element
{
	
	Node *q;    //����һ���½ڵ�q
	q = m_heap->m_next;    //��qָ������ĵ�һ���ڵ�
	if (location == 0)  //�����ҵ�λ�ò��Ϸ�ʱ���ͷ���false
	{
		return ERROR;
	}
	int j = 1;  //��һ���ڵ㿪ʼѭ�����������ǵ�ǰλ��
	while (q && j < location)  //��ǰλ�ò�������Ҫ�ҵ�Ԫ�ص�λ��ʱ��ѭ������
	{                         /*��p��û��Ϊ��ʱ�� ��ǰ��λ���Ѿ�������Ҫ���ҵ�λ�ã�ֱ���˳�ѭ��*/

		q = q->m_next;  //��qָ����һ���ڵ�
		j++;       //ÿѭ��һ�ε�ǰλ�ö������ƶ�һλ
	}
	if (!q || location > j)//P��û��ָ��գ�����ǰ��λ���Ѿ�������Ҫ�ҵ�λ�ã�������û���ҵ����ͷ��ش���
	{
		return ERROR;   //���ҵ�Ԫ�ز����� 
	}
	elemOut = q->m_data;   //ȡ��i��Ԫ�ص�����
	return OK;
}


Status ChainList::locateElemAt(ElemType &location, ElemType element)/*�����Ա��еĵ�locationλ�ò�����element��ȵ�Ԫ�أ�
													  ���ص�һ����element���Ԫ�������Ա��е��±꣬���򣬷���0*/
{
	Node *q = m_heap->m_next;  //��p�ĺ�̽ڵ���q
	int searchLocation=0;
	while (q != NULL)   //��q��Ϊ��ʱ�ͼ���ѭ��
	{
		++searchLocation;
		if (q->m_data == element)//���Ҫ���ҵ�Ԫ�ظպþ���q����������˳�ѭ��
			break;            //q�ǻ�����ѭ�����䶯��
		q = q->m_next;  //����ÿ��ѭ������q�ĺ�̽ڵ���q��������һ�ε�ѭ��
	}
	if (q == NULL)   //��qΪ��ʱ���ͷ��ش���
	{
		return ERROR;
	}
	location = searchLocation;  //��Ҫ���ҵ�Ԫ�ص�ֵ�Oλ����location���ظ�������
	return OK;
}

Status ChainList::listInsertAt(ElemType location, ElemType element)   //����Ԫ�أ�  �����Ա��е�location��λ��֮ǰ������Ԫ��element
{
	
	Node *q;  
	q = m_heap;    //��q���ͷ���ָ��
	int j = 1;    //��һ���ڵ㿪ʼѭ�����������ǵ�ǰλ��
	while (q && j < location) //��ǰλ�ò�������Ҫ�ҵ�Ԫ�ص�λ��ʱ��ѭ������
	{                       //��q��û��Ϊ��ʱ�� ��ǰ��λ���Ѿ�������Ҫ���ҵ�λ�ã�ֱ���˳�ѭ��
		q = q->m_next;   //q��ָ������ƶ�����ָ����һ���ڵ�
		++j;
	}
	if (!q || location < j) //P��û��ָ��գ�����ǰ��λ���Ѿ�������Ҫ�ҵ�λ�ã�������û���ҵ����ͷ��ش���
	{
		return ERROR;   //˵��Ҫ����ĵ�i��λ�ò�����
	}

	Node *s = new Node;  //����һ���µĽڵ�
	s->m_data = element;     //����Ԫ��e����s������
	s->m_next = q->m_next;  //��q�ĺ�̽ڵ���s�ĺ�̽ڵ�
	q->m_next = s;            //��s���q�ĺ�̽ڵ�
	m_heap->m_data = m_heap->m_data+2;     //���Ա�ĳ���ÿ�����2
	return OK;
}

Status ChainList::listRemoveAt(ElemType location, ElemType &elemOut)   // ɾ��������ɾ�����Ա��е�location��Ԫ�أ�Ȼ����element����
{
	
	Node *s, *q;
	int j = 1;
	s = m_heap;
	while (s->m_next && j < location)
	{                    //��p�ĺ�̽ڵ㻹û��ָ���ʱ�� ��ǰ��λ���Ѿ�������Ҫ���ҵ�λ�ã�ֱ���˳�ѭ��
		s = s->m_next;  //s��ָ������ƶ�����ָ����һ���ڵ�
		++j;
	}
	if (!(s->m_next) || j > location)  /*��p�ĺ�̽ڵ㻹û��ָ���ʱ��	
									   ����ǰ��λ���Ѿ�������Ҫ�ҵ�λ�ã�������û���ҵ����ͷ��ش���*/
	{
		return ERROR;//��i��Ԫ�ز�����
	}
	q = s->m_next;   //��s�ĺ�̽ڵ���q
	s->m_next = q->m_next;    //�ٰ�q�ĺ�̽ڵ���s�ĺ�̽ڵ�
	elemOut = q->m_data;  //��q�ڵ�����ݸ�element
	delete q;   //��ϵͳ���մ˽ڵ㣬�ͷ��ڴ�
	m_heap->m_data -=2;   //ÿɾ��һ���ڵ㣬���Ա�ĳ�����2
	return OK;
	
}

inline int ChainList::listLength()const  //�������Ա�ĳ���
{
	return m_heap->m_data;   //p->data  ��ʾ����ͷ���������򣬴洢���ǵ�����ĳ���
}

int main()
{
	ChainList *myChainList = new ChainList;  //����һ������,�Զ����ù��캯����ɶԵ�����ĳ�ʼ��

	//��ʼ��������
	int myLength=0;
	cout << "�봴���������ݵ�����";   
	cin >> myLength;
	int *myDatas = new int[myLength];   //ΪҪ�����ĵ��������ݷ���ռ䣬Ȼ��ѷ���Ŀռ�ĵ�ַ������myDatas
	cout << "������������" << myLength << "�����ݣ��м��Իس���������" << endl;
	for (int i = 0; i<myLength; i++)
	{
		cin >> myDatas[i];  //����Ҫ�洢�����ݵ�ֵ
	}
	myChainList->creatList(myDatas, myLength);
	cout << endl;
	//����´��������е�ֵ
	cout << "�½�������Ϊ" << myChainList->listLength() << ",��������Ϊ��" << endl;
	for (int i = 0; i<myLength; i++)
	{
		cout << myDatas[i] << " ";
	}
	cout << "\n\n";

	//��ȡ�����е�ֵ
	int readLocation=0;
	int readElement=0;
	cout << "������Ҫ��������������е�λ�ã�";
	cin >> readLocation;
	if (myChainList->getElemAt(readLocation, readElement))
	{
		cout << "�����е�" << readLocation << "������Ϊ��" << readElement << "\n" << endl;
	}
	else
		cout << "���ҵ�λ�ò��Ϸ���" << "\n" << endl;

	//����ĳһԪ���Ƿ�λ��������
	int findElement=0;
	int findLocation=0;
	cout << "������Ҫ���ҵ�Ԫ�أ�";
	cin >> findElement;
	if (myChainList->locateElemAt(findLocation, findElement))
	{
		cout << "�ҵ���Ԫ��" << findElement << "�����������е�����ֵΪ��" << findLocation << "\n" << endl;
	}
	else
		cout << "�����в����������ҵ�ֵ��" << "\n" << endl;

	//�������в���ֵ
	int insertLocation=0;
	int insertElement=0;
	cout << "������Ҫ�������ݵ�λ�ã�";
	cin >> insertLocation;
	cout << "������Ҫ��������ݵ�ֵ��";
	cin >> insertElement;
	cout << endl;
	if (myChainList->listInsertAt(insertLocation, insertElement))
	{
		cout << "�������ݳɹ��������������ʣ������ֵΪ��" <<endl;
		for (int i =1; i < myChainList->listLength();++i)
		{
			int localElement=0;
			myChainList->getElemAt(i, localElement);
			cout << localElement << " ";
		}
		cout << endl << endl;
	}
	else
		cout << "���ݲ���ʧ��,�����λ�ò�����" << "\n" << endl;

	//��������ɾ������
	int deleteLocation=0;
	int deleteElement=0;
	cout << "������Ҫɾ�����ݵڼ���λ�ã�";
	cin >> deleteLocation;
	if (myChainList->listRemoveAt(deleteLocation, deleteElement))
	{
		cout << "����ɾ���ɹ���ɾ�����ݺ�������ʣ������ֵΪ��" << endl;
		for (int i = 0; i < myChainList->listLength(); i++)
		{
			int localElement=0;
			myChainList->getElemAt(i + 1, localElement);
			cout << localElement << " ";
		}
		cout << endl << endl;
	}
	else
		cout << "����ɾ��ʧ�ܣ�ɾ����λ�ò�����" << "\n" << endl;

	//���������
	myChainList->clearList();

	//��������Ƿ�Ϊ��
	if (myChainList->listEmpty())
	{
		cout << "��������գ�" << endl;
	}
	else
		cout << "������δ��գ�" << endl;
	cout << endl;

	delete myDatas;  //�ͷ��������е�MyData������ڴ�
	delete myChainList; //�ͷ���������myChainList������ڴ�
	myDatas = NULL; //�¶��Ѿ��ͷŵ��ڴ��ڽ��н����ã��ֱ������ָ��Ķ��ڴ渳ֵΪNULL���ͷ��ڴ��Ҳ�����ڶ����ǽ���delete
	myChainList = NULL;

	cout << endl;
	system("pause");
	return 0;
}

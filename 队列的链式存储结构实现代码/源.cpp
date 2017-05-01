#include<iostream>
using namespace std;
#define TT_OK 1
#define TT_ERROR 0
typedef int ElemType;

class LinkQueue  //���е�����ṹ
{
public:
	struct QNode  //���еĽ��ṹ
	{
		ElemType m_data; //�����е�������
		QNode *m_next; //�����е�ָ����
	};
public:
	LinkQueue();
	~LinkQueue();
	ElemType isEmpty()const;   //�ж϶����Ƿ�Ϊ��
	ElemType clear();      //��ն���
	ElemType insert(ElemType elem);  //����Ԫ����������β��
	ElemType remove(ElemType &elemOut);  //ɾ�������еĶ�ͷԪ��
	ElemType destroy();      //���ٶ���
	ElemType getHead(ElemType &eleOut);  //��ȡ��ͷԪ��

	void getlength()const;  //�����еĵ�ǰ����
	void traverseElem();   //������ʾ�������е�����Ԫ��
private:
	QNode *m_front;  //�����еĶ�ͷָ�룬��ͷ������Ԫ�أ�ֻ��ͷ�������,��front==rearʱ������Ϊ��
	QNode *m_rear;  //�����еĶ�βָ��
	ElemType m_queLength;  //�����еĵ�ǰ����
};
LinkQueue::LinkQueue()
{
	m_front = m_rear = new QNode;  //Ϊ����ָ������ڴ�
	if (!m_front)
	{
		cout << "�����ڴ����ʧ�ܣ�" << endl;
	}
	m_front->m_next = nullptr;  //��ͷָ��ָ���
	m_queLength = 0;  
	cout << "*******************�����г�ʼ���ɹ�************************" << endl;
}
LinkQueue::~LinkQueue()
{
	this->destroy();
}
ElemType LinkQueue::insert(ElemType elem)
{
	QNode *p = new QNode;  //��һ���½ڵ�����ڴ�
	if (!p)  //��������󣬷��ش���
	{
		return TT_ERROR;
	}
	p->m_data = elem;  //���Ȱ�Ҫ����Ԫ�����������
	p->m_next = nullptr;  //�½��ĺ��ָ���
	m_rear->m_next = p;  //Ȼ���ڰ�p���ԭ��βָ��ָ��ĺ�̽��
	m_rear = p; //����ٰ�p����Ϊ��β��㣬��ʱm_rearָ��ָ�����һ��Ԫ��
	++m_queLength;  //���еĳ��ȼ�1
	return TT_OK;
}
ElemType LinkQueue::remove(ElemType &elemOut)
{
	if (m_front == m_rear)  //���ж��������Ƿ�Ϊ�գ��վʹ���
	{
		return TT_ERROR;
	}
	QNode *p = m_front->m_next; //����һ���½�㣬�ý�����Ҫɾ���ĵ�һ��Ԫ��
	elemOut = p->m_data;  //�ڰ�Ҫɾ����Ԫ����eleOut����
	m_front->m_next = p->m_next;  //�ڰ�Ҫ��ͷ���ĺ�̽�㣬���ڶ���Ԫ�أ�m_frontָ��ָ�������ͱ��ͷ���ĺ��
	if (m_rear == p)  //���Ҫɾ����Ԫ�ظպþ������һ��Ԫ�أ�  ��ʱ��һ��Ԫ��
	{
		m_rear = m_front;  //ɾ����m_rearָ��ָ��ͷ���
	}
	delete p;  //�ͷ�Ҫɾ���Ľ����ڴ�
	--m_queLength;  //�����еĵĳ��ȼ�һ
	return TT_OK;
}
ElemType LinkQueue::getHead(ElemType &eleOut)
{
	if (m_front == m_rear)  //���ж��������Ƿ�Ϊ�գ��վʹ���
	{
		return TT_ERROR;
	}
	//QNode *q=m_front->m_next; eleOut=q->m_data;
	eleOut = m_front->m_next->m_data;  //��m_frontָ��ָ��ĺ�̽���ָ�����е�������eleOut����
	return TT_OK;
}
ElemType LinkQueue::clear()  //��������У�������ͷ���
{
	QNode *m = m_front->m_next;  //��������һ����ʱ���m����ɶ�ͷԪ��
	m_front->m_next = nullptr; //Ȼ��m_frontָ��ָ��NULL
	m_rear = m_front;  //m_rearָ��ָ��ͷ���
	while (m)  //��m��Ϊ��ʱ��ѭ������
	{
		QNode *s = m->m_next;   //�Ȱ�m���ĺ�̽����s�����ڶ���Ԫ��
		delete m;  //�ͷ�m���
		m = s;  //Ȼ���ڰ�s �����m��㣬m�����Զ���ǵ�һ��Ԫ��
	}
	m_queLength = 0;
	return TT_OK;
}
ElemType LinkQueue::destroy()  //���ٶ��У�����ͷ���
{
	while (m_front)  //m_frontָ�벻NULL������
	{
		m_rear = m_front->m_next;  //���Ȱѵ�һ��Ԫ�ر��m_rearָ��
		delete m_front; //�ͷ�ͷ���
		m_front = m_rear;  //�ڰѵ�һ��Ԫ�ر��m_frontָ��
	}
	m_queLength = 0;
	return TT_OK;
}
void LinkQueue::traverseElem()   //������ʾ�������е�����Ԫ��
{
	if (m_front == m_rear)  //���ж��������Ƿ�Ϊ�գ��վʹ���
	{
		cout << "�˶�����û�����ݻ��߶���û�н���,�޷���ʾ��" << "\n" << endl;
	}
	cout << "���дӶ�ͷ����β��������Ϊ��"; 
	QNode *q = m_front->m_next;  //���Ȱѵ�һ��Ԫ�ر����ʱ����q
	while (q)  //ֻҪq��ΪNULL���ͼ���
	{
		cout << q->m_data << " ";  //��ʾ��qָ��ָ��Ľڵ��Ԫ��
		q = q->m_next;  //qָ��ÿѭ��һ�������ƶ�һ��
	}
	cout << endl;
}
inline ElemType LinkQueue::isEmpty()const
{
	return (m_front == m_rear);
}
inline void LinkQueue::getlength()const
{
	cout << "�����еĵ�ǰ��Ԫ�ظ���Ϊ��" << m_queLength << "\n" << endl;
}

int main()
{
	LinkQueue mylinkQueue; //��ʼ��һ������
	while (true)
	{
		{
			cout << ("\n*********************************************************") << endl
				<< "***************     �����еĻ�������չʾ    ******************" << endl
				<< "*******************************************************" << endl
				<< "**************      ѡ��1���� ���ݽ�����β.       ************" << endl
				<< "**************      ѡ��2���� ɾ������ͷԪ��.     ************" << endl
				<< "***************     ѡ��3���� ��ʾ����ͷԪ��.     ************" << endl
				<< "***************     ѡ��4���� �ж϶����Ƿ�Ϊ��.   ************" << endl
				<< "***************************************************************" << endl
				<< "***************     ѡ��5���� ��ʾ���е�Ԫ�ظ���. *************" << endl
				<< "***************     ѡ��6���� ��ն���.           *************" << endl
				<< "****************    ѡ��7���� ���ٶ���.           *************" << endl
				<< "****************    ѡ��8���� ��ʾ�����е�����Ԫ��. ***********" << endl
				<< "****************    ѡ��9���� ����.              *************" << endl
				<< "****************    ѡ��0���� �˳�����         *************" << endl
				<< "***************************************************************" << endl
				<< "***************************************************************" << endl;
		}
		 cout << "\n*************����������Ҫʹ�õ������й��ܵ����***************" << endl;
		 cout << "��������Ӧ����ţ�";
		 int userChoice(0);
		 cin >> userChoice;
		 if (userChoice == 0)
		 {
			 cout << "�������˳�����л����ʹ�ã�" << "\n" << endl;
			 break;
		 }
		 switch (userChoice)
		 {
		 case 1:
		 {
			 cout << "������������ӵ����ݣ�";
			 int pushDatas(0);
			 cin >> pushDatas;
			 if (mylinkQueue.insert(pushDatas))  //������ݽ���β
			 {
				 cout << "����" << pushDatas << "�����гɹ���"<< endl;
				 mylinkQueue.getlength();
				 mylinkQueue.traverseElem();
			 }
			 else
				 cout << "�ڴ����ʧ�ܣ�����" << pushDatas << "������ʧ�ܣ�" << "\n" << endl;
			 break;
		 }
		 case 2:
		 {
			 int popHead(0);
			 if (mylinkQueue.remove(popHead))  //ɾ����ͷԪ��
			 {
				 cout << "����" << popHead << "ɾ���ɹ���" << "\n" << endl;
				 mylinkQueue.getlength();
				 mylinkQueue.traverseElem();
			 }
			 else
			 {
				 cout << "Ŀǰ����Ϊ��,����" << popHead << "ɾ��ʧ�ܣ�" << "\n" << endl;
				 mylinkQueue.getlength();
			 }
			 break;
		 }
		 case 3:
		 {
			 int showHead(0);
			 if (mylinkQueue.getHead(showHead))  //��ʾ��ͷԪ��
			 {
				 cout << "�����е�ͷԪ��Ϊ��" << showHead << "\n" << endl;
				 mylinkQueue.getlength();
				 mylinkQueue.traverseElem();
			 }
			 else
			 {
				 cout << "Ŀǰ����Ϊ�գ��޷���ʾԪ�أ�" << "\n" << endl;
				 mylinkQueue.getlength();
			 }
			 break;
		 }
		 case 4:
			 if (mylinkQueue.isEmpty())  //�ж��������Ƿ�Ϊ��
			 {
				 cout << "�˶���Ϊ�գ�" << "\n" << endl;
				 mylinkQueue.getlength();
			 }
			 else
			 {
				 cout << "���в�Ϊ��" << "\n" << endl;
				 mylinkQueue.getlength();
				 mylinkQueue.traverseElem();
			 }
			 break;
		 case 5:                          //��ʾ�����е�ǰ��Ԫ�ظ���
			 mylinkQueue.getlength();  
			 mylinkQueue.traverseElem();
			 break;
		 case 6:
			 if (mylinkQueue.clear())  //��ն���
			 {
				 cout << "�����ѱ���գ�" << "\n" << endl;
				 mylinkQueue.getlength();
			 }
			 else
			 {
				 cout << "�������ʧ�ܣ�" << "\n" << endl;
				 mylinkQueue.getlength();
				 mylinkQueue.traverseElem();
			 }
			 break;
		 case 7:
		 {
			 cout << "��ȷ��Ҫ���ٴ˶������������٣����޷��ָ������������.��������������Y��y,��ʾȷ����";
			 char yesOrNo;
			 cin >> yesOrNo;
			 if ((yesOrNo == 'y') || (yesOrNo == 'y'))
			 {
				 if (mylinkQueue.destroy())
				 {
					 cout << "�����ѱ����٣�" << "\n" << endl;
				 }
				 else
					 cout << "��������ʧ�ܣ�" << "\n" << endl;
			 }
			 break;
		 }
		 case 8:                          //��ʾ�����е�����Ԫ��
			 mylinkQueue.getlength();
			 mylinkQueue.traverseElem();  
			 break;
		 case 9:
			 system("cls");
			 cout << "��Ļ�Ѿ�������������������!" << "\n" << endl;
			 break;
		 default:
			 cout << "�������Ų���ȷ������������!" << "\n" << endl;
		 }
	}
	system("pause");
	return 0;
}
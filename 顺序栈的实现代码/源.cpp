#include<iostream>
#include<cassert>
using namespace std;
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef  bool Status;
class Stack
{
public:

	Stack(ElemType STACK_INIT_SIZE); //  ��ʼ������������һ����ջ
	~Stack();//�����������ͷ��ڴ�
	Status stackFull()const; //ȷ��ջ�Ƿ�����
	Status destroyStack();  //��ջ���ڣ���������
	Status clearStack();  //��ջ���
	Status stackEmpty()const;  //��ջΪ�գ�����true ����false

	ElemType getTopAt(ElemType &elemOut);  //��ջ�����ҷǿգ���e����ջ��ջ��Ԫ��
	ElemType pushAt(ElemType e); //��ջ���ڣ�������Ԫ��e ��Ϊջ��Ԫ��
	ElemType popAt(ElemType &elemOut);  //ɾ��ջ��ջ��Ԫ�أ�����e������ֵ

	Status getLength()const;  //����ջ�е�Ԫ�ظ���
	void showStack();  //��ʾջ������Ԫ��
private:
	ElemType *m_top;  //ָ��ջ��Ԫ�ص�ָ��
	ElemType *m_base;   //ָ��ջ��Ԫ�ص�ָ��
	ElemType m_stackSize;  //ջ��ǰ��Ԫ������
};
Stack::Stack(ElemType STACK_INIT_SIZE)  //��ʼ��ջ
{
	m_base = new ElemType(STACK_INIT_SIZE);  //Ϊջ����ռ�
	if (!m_base)  //��û�з��䵽�ռ䣬����false
	{
		cout << "��ʼ��ʧ��!" << "\n" << endl;
	}
	m_top = m_base;  //�ʼ��ջ������ջ��
	m_stackSize = STACK_INIT_SIZE; //����ջ���������Ϊ100
	assert(STACK_INIT_SIZE > 0);
	cout << "��ʼ���ɹ���ջ�Ĵ�С��: " << m_stackSize << "\n" << endl;
}
Stack::~Stack()  //�ͷŷ�����ڴ�
{
	delete m_base;
}
ElemType Stack::pushAt(ElemType e)  //Ϊջ���Ԫ��
{
	if (m_top - m_base >= m_stackSize)
	{
		return ERROR;
	}
	*(m_top) = e;
	++m_top;
	return OK;

}
ElemType Stack::popAt(ElemType &elemOut)  //ɾ��ջ��Ԫ��
{
	if (m_top == m_base) //��ջ��ָ���ջ��ָ���غϣ�˵��ջ��û��Ԫ��
	{
		return ERROR;
	}
	//--Top;  //ջ��ָ���������ƶ�һ��
	elemOut = *--(m_top);  //Ȼ��ȡ��ջ��ָ��ָ�ŵ�Ԫ��
	return OK;;

}
inline Status Stack::clearStack()  //�������Ԫ��
{
	m_top = m_base;
	return OK;  //��ջ��ָ���ջ��ָ���غϣ�˵��ջ��û��Ԫ��
}

inline Status Stack::getLength()const //����ջ�ĵ�ǰ��Ԫ������
{
	cout << "ջ�е�Ԫ�ظ���Ϊ��" << (m_top - m_base) << "\n" << endl;
	return OK;
}
inline Status Stack::stackEmpty()const //�ж�ջ�Ƿ�Ϊ��
{
	return  (m_base == m_top || m_stackSize == 0);
}

Status Stack::destroyStack()  //�ݻ�ջ
{
	delete m_base;    //�ѷ�����ڴ��ͷŵ�
	m_base = m_top = NULL;  //ջ��ָ���ջ��ָ�붼ָ���
	m_stackSize = 0;  //Ȼ���ջ�������������Ϊ0
	return OK;
}
Status Stack::stackFull()const  //�ж��Ƿ�ջ��
{
	int temp = (m_top - m_base);
	if (temp == m_stackSize)
	{
		cout << "Ŀǰջ������ջ��δ����!" << "\n" << endl;
	}
	else
		cout << "Ŀǰջ�����������Լ����������ݽ�ջ!" << "\n" << endl;
	return OK;
}
ElemType Stack::getTopAt(ElemType &e)  //�õ�ջ��Ԫ��
{
	if (m_base == m_top)
	{
		cout << "���󣬷��ʵ�λ�ò���ȷ" << "\n" << endl;
		return ERROR;
	}
	e = *--(m_top);
	++m_top;
	return OK;
}
void Stack::showStack()  //��ʾջ�е�����Ԫ��
{
	if (m_base == m_top)
	{
		cout << "��ջ��û�����ݣ�����ջδ������" << "\n" << endl;
	}
	int Temp = (m_top - m_base);  //�����ջ�е�Ԫ�صĸ���
	m_top = m_base;  //��ջ��ָ����ջ��ָ�룬��ջ�׿�ʼ�������
	cout << "��ʾ��ջ�е�����Ԫ�أ�";
	for (int i = 1; i <= Temp; ++i)
	{
		cout << *(m_top)++ << ",";
	}
}
void testStack()
{
	Stack myStack(5);  //����һ������ ������ʼ��100
	while (1)
	{
		{
			cout << endl;
			cout << "===================" << endl;
			cout << "˳��ջ�Ļ�����������." << endl;
			cout << "===================" << "\n" << endl;
			cout << "ѡ��1�������ݽ�ջ." << endl;
			cout << "ѡ��2����ջ�����ݳ�ջ." << endl;
			cout << "ѡ��3�����ж�ջ�Ƿ�Ϊ��." << endl;
			cout << "ѡ��4��������ջ�е�Ԫ�ظ���." << endl;
			cout << "===================" << endl;
			cout << "ѡ��5�����ж�ջ�Ƿ�����." << endl;
			cout << "ѡ��6�������ջ��ջ��Ԫ��." << endl;
			cout << "ѡ��7�������ջ������Ԫ��." << endl;
			cout << "ѡ��8������ջ���." << endl;
			cout << "ѡ��9��������һ��ջ." << endl;
			cout << "===================" << endl;
			cout << "ѡ��10��������." << endl;
			cout << "ѡ��0�����˳�����." << endl << endl;
			cout << "===================" << endl;
		}
		cout << "���������ѡ��: " << endl;
		int userChoice = 0;
		cin >> userChoice;
		if (userChoice == 0)
		{
			cout << "�������˳�����л����ʹ��!" << "\n" << endl;
			break;
		}

		switch (userChoice)
		{
		case 1:
		{
			cout << "������Ҫ��ջ�����ݣ�";
			int pushData = 0;
			cin >> pushData;
			if (myStack.pushAt(pushData))
			{
				cout << "���� " << pushData << "�Ѿ���ջ�ɹ�!" << "\n" << endl;

			}
			else
				cout << "���� " << pushData << "û����ջ�ɹ�!" << "\n" << endl;
			break;
		}
		case 2:
		{
			int removeData = 0;
			if (myStack.popAt(removeData))
			{
				cout << "��ջ�гɹ���ջ������Ϊ: " << removeData << "\n" << endl;
			}
			else
				cout << "��ջʧ��!" << "\n" << endl;
			break;
		}
		case 3:
		{
			if (myStack.stackEmpty())
			{
				cout << "Ŀǰ�ǿ�ջ������ջ��δ����!" << "\n" << endl;
			}
			else
				cout << "Ŀǰջ�ǿ�!" << "\n" << endl;
			break;
		}
		case 4:
			myStack.getLength();  //�õ�ջ�д�ʱ��Ԫ�ظ���
			break;
		case 5:
			myStack.stackFull();  //�ж��Ƿ�ջ��
			break;
		case 6:
		{
			int getElement = 0;
			if (myStack.getTopAt(getElement))
			{
				cout << "ջ��Ԫ��Ϊ��" << getElement << "\n" << endl;
			}
			break;
		}
		case 7:
			myStack.showStack();  //��ʾջ�е�Ԫ�أ���ջ�׿�ʼ�����
			break;

		case 8:
		{
			if (myStack.clearStack())
			{
				cout << "ջ�Ѿ����." << "\n" << endl;
			}
			else
				cout << "ջû�б����." << "\n" << endl;
			break;
		}
		case 9:
		{
			char yesOrNo;
			cout << "��ȷ��Ҫ����һ��ջ��?(����������������(Y/y))";
			cin >> yesOrNo;
			if ((yesOrNo == 'Y') || (yesOrNo == 'y'))
			{
				if (myStack.destroyStack())
				{
					cout << "ջ�ѱ�����." << "\n" << endl;
				}
				else
					cout << "ջû�б�����." << "\n" << endl;
			}
			break;
		}
		case 10:
			system("cls");
			cout << "��Ļ�Ѿ�������������������!" << "\n" << endl;
			break;
		default:
			cout << "�������Ų���ȷ������������!" << "\n" << endl;
		}
	}
}
int main()
{
	testStack();
	system("pause");
	return 0;
}
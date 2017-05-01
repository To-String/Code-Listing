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

	Stack(ElemType STACK_INIT_SIZE); //  初始化操作，建立一个空栈
	~Stack();//析构函数，释放内存
	Status stackFull()const; //确定栈是否已满
	Status destroyStack();  //若栈存在，则销毁它
	Status clearStack();  //将栈清空
	Status stackEmpty()const;  //若栈为空，返回true 否则false

	ElemType getTopAt(ElemType &elemOut);  //若栈存在且非空，用e返回栈的栈顶元素
	ElemType pushAt(ElemType e); //若栈存在，插入新元素e 成为栈顶元素
	ElemType popAt(ElemType &elemOut);  //删除栈的栈顶元素，并用e返回其值

	Status getLength()const;  //返回栈中的元素个数
	void showStack();  //显示栈的所以元素
private:
	ElemType *m_top;  //指向栈顶元素的指针
	ElemType *m_base;   //指向栈底元素的指针
	ElemType m_stackSize;  //栈当前的元数个数
};
Stack::Stack(ElemType STACK_INIT_SIZE)  //初始化栈
{
	m_base = new ElemType(STACK_INIT_SIZE);  //为栈分配空间
	if (!m_base)  //若没有分配到空间，返回false
	{
		cout << "初始化失败!" << "\n" << endl;
	}
	m_top = m_base;  //最开始，栈顶就是栈底
	m_stackSize = STACK_INIT_SIZE; //现在栈的最大容量为100
	assert(STACK_INIT_SIZE > 0);
	cout << "初始化成功，栈的大小是: " << m_stackSize << "\n" << endl;
}
Stack::~Stack()  //释放分配的内存
{
	delete m_base;
}
ElemType Stack::pushAt(ElemType e)  //为栈添加元素
{
	if (m_top - m_base >= m_stackSize)
	{
		return ERROR;
	}
	*(m_top) = e;
	++m_top;
	return OK;

}
ElemType Stack::popAt(ElemType &elemOut)  //删除栈顶元素
{
	if (m_top == m_base) //当栈底指针和栈顶指针重合，说明栈中没有元素
	{
		return ERROR;
	}
	//--Top;  //栈顶指针先往下移动一格
	elemOut = *--(m_top);  //然后取出栈顶指针指着的元素
	return OK;;

}
inline Status Stack::clearStack()  //清空所有元素
{
	m_top = m_base;
	return OK;  //当栈顶指针和栈底指针重合，说明栈中没有元素
}

inline Status Stack::getLength()const //计算栈的当前的元数个数
{
	cout << "栈中的元素个数为：" << (m_top - m_base) << "\n" << endl;
	return OK;
}
inline Status Stack::stackEmpty()const //判断栈是否为空
{
	return  (m_base == m_top || m_stackSize == 0);
}

Status Stack::destroyStack()  //摧毁栈
{
	delete m_base;    //把分配的内存释放掉
	m_base = m_top = NULL;  //栈顶指针和栈底指针都指向空
	m_stackSize = 0;  //然后把栈的最大容量设置为0
	return OK;
}
Status Stack::stackFull()const  //判断是否栈满
{
	int temp = (m_top - m_base);
	if (temp == m_stackSize)
	{
		cout << "目前栈满或者栈尚未建立!" << "\n" << endl;
	}
	else
		cout << "目前栈不满，还可以继续输入数据进栈!" << "\n" << endl;
	return OK;
}
ElemType Stack::getTopAt(ElemType &e)  //得到栈顶元素
{
	if (m_base == m_top)
	{
		cout << "错误，访问的位置不正确" << "\n" << endl;
		return ERROR;
	}
	e = *--(m_top);
	++m_top;
	return OK;
}
void Stack::showStack()  //显示栈中的所有元素
{
	if (m_base == m_top)
	{
		cout << "此栈中没有数据，或者栈未建立！" << "\n" << endl;
	}
	int Temp = (m_top - m_base);  //先算出栈中的元素的个数
	m_top = m_base;  //把栈底指针变成栈顶指针，从栈底开始遍历输出
	cout << "显示出栈中的所有元素：";
	for (int i = 1; i <= Temp; ++i)
	{
		cout << *(m_top)++ << ",";
	}
}
void testStack()
{
	Stack myStack(5);  //创建一个对象 容量初始化100
	while (1)
	{
		{
			cout << endl;
			cout << "===================" << endl;
			cout << "顺序栈的基本操作程序." << endl;
			cout << "===================" << "\n" << endl;
			cout << "选择1——数据进栈." << endl;
			cout << "选择2——栈顶数据出栈." << endl;
			cout << "选择3——判断栈是否为空." << endl;
			cout << "选择4——返回栈中的元素个数." << endl;
			cout << "===================" << endl;
			cout << "选择5——判断栈是否满了." << endl;
			cout << "选择6——输出栈的栈顶元素." << endl;
			cout << "选择7——输出栈的所有元素." << endl;
			cout << "选择8——将栈清空." << endl;
			cout << "选择9——销毁一个栈." << endl;
			cout << "===================" << endl;
			cout << "选择10——清屏." << endl;
			cout << "选择0——退出程序." << endl << endl;
			cout << "===================" << endl;
		}
		cout << "请输入你的选择: " << endl;
		int userChoice = 0;
		cin >> userChoice;
		if (userChoice == 0)
		{
			cout << "程序已退出，感谢您的使用!" << "\n" << endl;
			break;
		}

		switch (userChoice)
		{
		case 1:
		{
			cout << "请输入要进栈的数据：";
			int pushData = 0;
			cin >> pushData;
			if (myStack.pushAt(pushData))
			{
				cout << "数据 " << pushData << "已经入栈成功!" << "\n" << endl;

			}
			else
				cout << "数据 " << pushData << "没有入栈成功!" << "\n" << endl;
			break;
		}
		case 2:
		{
			int removeData = 0;
			if (myStack.popAt(removeData))
			{
				cout << "从栈中成功出栈的数据为: " << removeData << "\n" << endl;
			}
			else
				cout << "出栈失败!" << "\n" << endl;
			break;
		}
		case 3:
		{
			if (myStack.stackEmpty())
			{
				cout << "目前是空栈或者是栈尚未建立!" << "\n" << endl;
			}
			else
				cout << "目前栈非空!" << "\n" << endl;
			break;
		}
		case 4:
			myStack.getLength();  //得到栈中此时的元素个数
			break;
		case 5:
			myStack.stackFull();  //判断是否栈满
			break;
		case 6:
		{
			int getElement = 0;
			if (myStack.getTopAt(getElement))
			{
				cout << "栈顶元素为：" << getElement << "\n" << endl;
			}
			break;
		}
		case 7:
			myStack.showStack();  //显示栈中的元素，从栈底开始输出的
			break;

		case 8:
		{
			if (myStack.clearStack())
			{
				cout << "栈已经清空." << "\n" << endl;
			}
			else
				cout << "栈没有被清空." << "\n" << endl;
			break;
		}
		case 9:
		{
			char yesOrNo;
			cout << "你确定要销毁一个栈吗?(若销毁请输入输入(Y/y))";
			cin >> yesOrNo;
			if ((yesOrNo == 'Y') || (yesOrNo == 'y'))
			{
				if (myStack.destroyStack())
				{
					cout << "栈已被销毁." << "\n" << endl;
				}
				else
					cout << "栈没有被销毁." << "\n" << endl;
			}
			break;
		}
		case 10:
			system("cls");
			cout << "屏幕已经清屏，可以重新输入!" << "\n" << endl;
			break;
		default:
			cout << "输入的序号不正确，请重新输入!" << "\n" << endl;
		}
	}
}
int main()
{
	testStack();
	system("pause");
	return 0;
}
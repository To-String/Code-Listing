#include<iostream>
#include<cassert>
using namespace std;
#define TT_OK 1
#define TT_ERROR 0
typedef  int ElemType;
typedef void Status;
class SqList
{
public:
	SqList(ElemType maxSize);
	~SqList();
	ElemType insertAt(ElemType i, ElemType elem);
	ElemType removeAt(ElemType i, ElemType &elemOut);
	ElemType getAt(ElemType i, ElemType &elemOut);
	
	ElemType getIndexElem(const ElemType elem);//查找与e相等的元素，返回第一个与e相等元素在线性表中的下标，否则，返回0
	ElemType isEmpty()const;
	Status getLength()const;
	Status clear();
	Status show();
	ElemType isFull()const;
	ElemType destroy();
private:
	ElemType *m_data;  
	ElemType  m_length;  //线性表当前的元素个数
	ElemType  m_maxLength; //线性表的最大容量
	
};
SqList::SqList(ElemType maxSize)
{
	assert(maxSize > 0);
	m_data = new ElemType[maxSize];
	if (!m_data)
	{
		cout << "错误！内存分配失败！" << endl;
	}
	m_length = 0;
	m_maxLength = maxSize;
	cout << "********************顺序表初始化成功********************" << "\n" << endl;
}
SqList::~SqList()
{
	this->destroy();
}
ElemType SqList::insertAt(ElemType i, ElemType elem) //插入元素，  在线性表中第i个位置之前插入新元素elem
{                                               //if(i<0 || i>length)
	if ((m_length == m_maxLength)||(i<1 || i>m_length + 1))  //当顺序表已满，或插入的位置不合理时，返回错误
	{
		return TT_ERROR;
	}
	if (i <= m_length)  //若插入的位置不在表尾，否则直接插入新元素，只有插入第11个位置才算是表尾
	{
		for (int k = m_length; k >= i; --k)  /*元素i及其后面的元素都往后移一下以腾出i处的空间存放要插入的元素,*/
			m_data[k] = m_data[k - 1];  //假如m_length=10,m_maxSize=20;那么第一次就是把下标为9的元素变成下标为10的元素
		                              //相当于元素向后移，每次循环都是如此，k为为线性表当前长度，每次循环减一
	}
	m_data[i - 1] = elem; //将新元素插入第i个位置之前
	++m_length;
	return TT_OK;
}
ElemType SqList::removeAt(ElemType i, ElemType &elemOut)  //删除元素线性表中第i个数据元素，并用elem返回其值,表长减一
{
	if ((m_length == 0)|| (i<1 || i>m_length))/*假如m_length=10,m_maxSize=20;线性表是是第一个位置数，没有第0个位置，
		                        删除的线性表的位置不能大于当前线性表的长度,或者当前没有元素，说白了就是删除位置
								 不合理*/
	{
		return TT_ERROR;
	}
	elemOut = m_data[i - 1];  //把当前下标的元素用elemOut取出
	if (i<m_length)     //如果要删除的不是最后位置
	{
		for (int k = i; k < m_length;++k)     //将删除位置后的元素向前移动，  要删除的位置不能大于表长
			 m_data[k - 1] = m_data[k];  //那么第一次循环就是把下标为10的元素变成下标为9的元素，每次循环向前移动
	}
	--m_length;
	return TT_OK;
}
ElemType SqList::getAt(ElemType i, ElemType &elemOut) //获得元素的操作,将线性表中第i个位置的元素的值返回给e
{
	if ((m_length == 0) || (i<1 || i>m_length))  //当你获取的元素不在线性表中的范围，就错误呗
	{
		return TT_ERROR;
	}
	elemOut = m_data[i - 1];
	return TT_OK;
}

ElemType SqList::getIndexElem(const ElemType elem)//在线性表中查找与elem的相等的元素，返回第一个与elem相等元素在线性表中的第几个位置
{
	for (int i = 0; i < m_length; ++i)  //假如m_length=10,m_maxSize=20;那么下标最大到9
	{
		if (m_data[i] == elem)  /*把elem相等的元素返回，因为线性表是从1开始的，数组的下标是0开始的，于是线性表第i个元素存储在
					      数组下标i-1的位置，返回的时候要加1*/
			return i + 1;
	}
	return TT_OK;
}
		

Status SqList::clear()
{
	m_data = nullptr;
	m_length = 0;
	if (!m_data && m_length == 0)
	{
		cout << "顺序表已清空！" << endl;
	}
	else
		cout << "顺序表清空失败！" << endl;
}
Status SqList::show()
{
	if (m_length == 0)
	{
		cout << "错误！当前线性表没有元素，无法显示！" << endl;
	}
	cout << "输出线性表的所有元素为：";
	for (int k = 0; k < m_length; ++k)
	{
		cout<< m_data[k] << " ";
	}
	cout << endl;
}
ElemType SqList::destroy()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = m_maxLength = 0;
	return TT_OK;
}
inline ElemType SqList::isFull()const  //判断是否满了
{
	return (m_length == m_maxLength);
}
inline ElemType SqList::isEmpty()const
{
	return (m_length == 0);
}
inline Status SqList::getLength()const
{
	cout << "当前的顺序表的长度为：" << m_length << endl;
}
void testMySqList()
{
		int sizeCapacity(0);
		cout << "输入顺序表的最大容量：";
		cin >> sizeCapacity;
		SqList mySqList(sizeCapacity);
	while (true)
	{
		{
			cout << "*************************************************************" << endl
				<< "*******************   顺序表的基本功能展示   *******************" << endl
				<< "*****************************************************************" << endl
				<< "********************   选择1——数据插入.   **********************" << endl
				<< "********************   选择2——数据删除.   **********************" << endl
				<< "********************   选择3——获取元素.   **********************" << endl
				<< "********************   选择4——查找元素.   **********************" << endl
				<< "********************   选择5——是否为空.   **********************" << endl
				<< "********************   选择6——获取线性表的长度.   **********************" << endl
				<< "********************   选择7——清空元素.   **********************" << endl
				<< "********************   选择8——显示所有元素.   **********************" << endl
				<< "********************   选择9——是否为满.    **************************" << endl
				<< "*********************  选择10——销毁线性表.  ************************" << endl
				<< "**********************  选择11——清屏！      ************************" << endl
				<< "**********************  选择0——退出程序！   ************************" << endl
				<< "***********************************************************************" << endl
				<< "***********************************************************************" << endl;
		}
		cout << "\n********************   请输入你想要使用的顺序表功能的序号   ***************" << endl;
		cout << "请输入你的选择：";
		int userChoice(0);
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
			int pushDatas(0);  //要插入的元素
			int indexLocition(0);  //要插入的位置
			cout << "请输入你想要插入的元素位置：";
			cin >> indexLocition;
			cout << "请输入你想要插入的元素：";
			cin >> pushDatas;
			if (mySqList.insertAt(indexLocition, pushDatas))
			{
				cout << "数据" << pushDatas << "插入成功！" << "\n" << endl;
				mySqList.getLength();
				mySqList.show();
			}
			else
				cout << "当前顺序表已满或者插入位置不合理，数据" << pushDatas << "插入失败！" << endl;
			break;
		}
		case 2:
		{
			int popDatas(0);  //要删除的元素
			int indexLocition(0);  //要删除的位置
			cout << "请输入你想要删除的元素的位置：";
			cin >> indexLocition;
			if (mySqList.removeAt(indexLocition, popDatas))
			{
				cout << "数据" << popDatas << "删除成功！" << "\n" << endl;
				mySqList.getLength();
				mySqList.show();
			}
			else
				cout << "当前顺序表为空或者删除位置不合理，数据" << popDatas << "删除失败！" << endl;
			break;
		}
		case 3:
		{
			int getElem(0);  //要获取的元素
			int indexLocition(0);
			cout << "请输入你想要获取元素的位置：";
			cin >> indexLocition;
			if (mySqList.getAt(indexLocition, getElem))
			{
				cout << "获取的元素为：" << getElem << "\n" << endl;
				mySqList.getLength();
				mySqList.show();
			}
			else
				cout << "当前顺序表为空或者获取的位置不合理，数据" << getElem << "获取失败！" << endl;
			break;
		}
		case 4:
		{
			int findElem(0);   //查找元素
			cout << "请输入你想要查找的元素的值：";
			cin >> findElem;
			int indexLocition = mySqList.getIndexElem(findElem);
			if (!indexLocition)
			{
				cout << "当前表中无此元素" << endl;
				mySqList.getLength();
			}
			else
			{
				cout << "所要查找的元素位于表中第" << indexLocition << "个位置" << endl;
				mySqList.getLength();
				mySqList.show();
			}
			break;
		}
		case 5:
			if (mySqList.isEmpty())  //判断是否为空
			{
				cout << "目前该顺序表为空！" << endl;
				mySqList.getLength();
			}
			else
			{
				cout << "目前顺序表非空！" << endl;
				mySqList.getLength();
				mySqList.show();

			}
			break;
		case 6:
			mySqList.getLength();  //获取线性表的长度
			break;
		case 7:
			mySqList.clear();//清空所有元素   
			break;
		case 8:
			mySqList.show();//显示所有元素
			break;
		case 9:
			if (mySqList.isFull())
			{
				cout << "目前该顺序表为满！不能再增加元素了！" << endl;
			}
			else
				cout << "目前该顺序表非满，还可以增加元素！" << endl;
			break;
		case 10:
		{
			cout << "你确定要销毁该顺序表吗？(若销毁请输入输入(Y/y))";
			char yesOrNo;
			cin >> yesOrNo;
			if ((yesOrNo == 'Y') || (yesOrNo == 'y'))
			{
				if (mySqList.destroy())
				{
					cout << "顺序表已被销毁." << "\n" << endl;
				}
				else
					cout << "顺序表没有被销毁." << "\n" << endl;
			}
			break;
		}
		case 11:
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
	testMySqList();
	system("pause");
	return 0;
}
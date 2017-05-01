#include<iostream>
#include<cassert>
using namespace std;
typedef size_t IndexType; /// 我们定义下标为size_t
typedef int ElemType;

/// 通常我们的类名第一个字母都是大写,而变量名和成员函数名第一个字母是小写
class SeqList
{
public:
	///你可以把最大个数作为参数传递进去，而不用用MAXSIZE=100来"写死"
	SeqList(size_t maxSize);
	~SeqList();
	size_t getLength() const; 
	bool isEmpty() const; 
						   /// 这个函数名字应该叫 获取下标所以我把其从LocateElem改成getIndex
	IndexType getIndex(const ElemType e) const; 
	void clear(); //将线性表清空
	bool getAt(IndexType i, ElemType& elemOut) const;   //在线性表中查找第i个元素
	bool insertAt(IndexType i, ElemType  e); //在线性表中第i个位置插入值为e的元素
											
	bool removeAt(IndexType i, ElemType& elemOut);// 删除操作，删除线性表中第i个元素
private:
	ElemType* m_data;  //线性表中的数据元素，他存储的位置就是存储空间的存储位置
	size_t    m_length;//线性表当前长度
	size_t    m_maxSize;
};
inline size_t SeqList::getLength()const   //返回是线性表中的个数
{
	return m_length;
}
inline bool SeqList::isEmpty() const
{
	return m_length == 0; ///这里使用一条语句就可以了，而你写了三条语句
}
//我们通常使用构造函数中初始化各种数据成员
SeqList::SeqList(size_t maxSize)
	: m_length(0)
	, m_maxSize(m_maxSize)
	, m_data(new ElemType[maxSize])
{
	assert(maxSize > 0);//然后使用断言来做一些参数检查
	cout << "构造线性表,长度: " << maxSize << endl;
}
SeqList::~SeqList()
{
	delete[] m_data;//注意: C++中你new了一块内存必须要delete掉你的内存，否则会导致你程序"内存泄漏"
	cout << "线性表已摧毁" << endl;
}
IndexType SeqList::getIndex(const ElemType e) const      /*线性表中查找与e相等的元素，返回第一个与e相等元素在线性表中的序号，若返回的
														 是下标就可以不用+1*/
{
	for (int i = 0; i < m_length; ++i)
	{
		if (*(m_data + i) == e)  //查找线性表中有没有跟e相等的元素
			return i + 1;    /*把e相等的元素返回，因为线性表是从1开始的，数组的下标是0开始的，于是线性表第i个元素存储在
							 数组下标i-1的位置，返回的时候要加1*/
	}
	return 0;

}
void SeqList::clear()   //将线性表的元素清空
{
	//m_data = NULL; //内存不用释放,只要重置length为0就可以了
	m_length = 0;
}
//获得元素的操作,将线性表中第i个位置的元素的值返回给e
bool SeqList::getAt(IndexType i, ElemType& elemOut)const
{
	if (m_length == 0 || i<1 || i>m_length)  //判断当前线性表是为为空、或者i益出就返回错误
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
	elemOut = *(m_data + i - 1); //把第i个元素返回给e
	return true;
}
//插入元素，  在线性表中第i个位置之前插入新元素e
bool SeqList::insertAt(IndexType i, ElemType e)
{
	if (m_length == m_maxSize) //线性表已满
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}

	if (i<1 || i>m_length + 1)     //当i不在范围益处的时候
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
	if (i <= m_length)    //若插入的数据不在表尾,若在表尾直接跳过if语句
	{
		for (int k = m_length; k >= i; k--)  /*元素i及其后面的元素都往后移一下以腾出i处的空间存放要插入的元素,*/
			*(m_data + k) = *(m_data + k - 1);  //就是data[k-1]，  就是把k-1的元素变成k的元素，相当于向后移动
	}
	*(m_data + i - 1) = e;  //将新元素插入
	m_length++;    //表长加1
	return true;
}

//删除元素线性表中第i个数据元素，并用e返回其值， 表长减一
bool SeqList::removeAt(IndexType i, ElemType& elemOut)
{
	if (m_length == 0)     //线性表为空时
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
	if (i<1 || i>m_length)       //删除的位置不正确
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
	elemOut = *(m_data + i - 1);   //取出要删除的元素
	if (i<m_length)     //如果要删除的不是最后位置
	{
		for (int k = i; k<m_length; k++)     //将删除位置后的元素向前移动，  要删除的位置不能大于表长
			*(m_data + k - 1) = *(m_data + k);
	}
	m_length--;    //表长减一
	return true;
}

/// 测试你的SeqList
void TestSeqList()
{
	SeqList sq1(100);
	{/// 把相似的代码或属于同一逻辑的用花括号括起来这样就方便阅读，结构更清晰.
		sq1.insertAt(1, 5);
		sq1.insertAt(2, 8);
		sq1.insertAt(3, 2);
		sq1.insertAt(4, 6);
		sq1.insertAt(5, 15);
		sq1.insertAt(6, 10);
		sq1.insertAt(6, 2);
	}
	cout << "插入值后，表的当前长度为：" << sq1.getLength() << "\n\n";

	for (int i = 0; i < sq1.getLength(); ++i)
	{
		int e = 0; //表示要输出的元素
		sq1.getAt(i + 1, e);
		cout << "表中第" << (i + 1) << "个元素为" << e << "\n";
	}
	cout << endl;

	//删除数据
	{
		int IndexType, deleteLocation = 0;
		cout << "请输入要删除的元素的位置：";
		cin >> deleteLocation;    //要删除的位置
		int ElemType, deleteElement = 0;   //要删除的元素
		sq1.removeAt(deleteLocation, deleteElement);
		cout << "删除了表中第" << deleteLocation << "个元素，该元素为：" << deleteElement << "\n\n";
	}
	//输出删除后表中的数据
	for (IndexType i = 0; i < sq1.getLength(); ++i)
	{
		int ElemType, e(0);
		sq1.getAt(i + 1, e);
		cout << "删除后的表中第" << (i + 1) << "个元素为" << e << "\n";
	}
	cout << endl;

	//查找表中的数据
	{
		int ElemType, searchElement = 0;
		cout << "请输入要查找的元素的值：";
		cin >> searchElement;
		cout << endl;
		int IndexType, searchLocation = sq1.getIndex(searchElement);
		if (!searchLocation)
			cout << "当前表中无此元素" << endl;
		else
			cout << "所要查找的元素位于表中第" << searchLocation << "个位置" << endl;
	}
	cout << endl;

	//清空表
	{
		sq1.clear();
		//判断表是否为空
		if (sq1.isEmpty())
			cout << "当前表为空表！" << endl;
		else
			cout << "当前表非空！" << endl;
	}

	cout << endl;
}
int main()
{
	TestSeqList();
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
#define true 1
#define false 0
typedef int ElemType;
typedef  int Status;
#define MAXSIZE 100   //存储空间初始分配量
class sqList
{
public:
	unsigned int ListLength()const; //获得线性表中的个数
	bool InitList(); //初始化线性表
	bool ListEmpty();  //判断线性表是否为空

	Status LocateElem(const ElemType e); //线性表中查找与e相等的元素，返回第一个与e相等元素在线性表中的下标，否则，返回0
	void ClearList(); //将线性表清空
	bool DestroyList();//销毁线性表  

	Status GetElem(int i, ElemType &e);   //在线性表中查找第i个元素
	Status ListInsert(int i, ElemType e); //在线性表中第i个位置插入值为e的元素
	Status ListDelete(int i, ElemType &e);// 删除操作，删除线性表中第i个元素

private:
	ElemType *data;  //线性表中的数据元素，他存储的位置就是存储空间的存储位置
	ElemType length;   //线性表当前长度

};


bool sqList::DestroyList()  //线性表摧毁
{
	delete[]data;
	data = NULL;
	if (!data)
	{
		cout << "线性表已摧毁" << endl;
		return true;
	}
	else
		cout << "线性表没有摧毁" << endl;
	return false;
}
inline unsigned int sqList::ListLength()const   //返回是线性表中的个数
{
	return length;
}
bool sqList::ListEmpty()  //判断的是线性表是否为空，
{
	if (length == 0)
		return true;
	return false;
}
Status sqList::LocateElem(const ElemType e)       /*线性表中查找与e相等的元素，返回第一个与e相等元素在线性表中的序号，若返回的
											   是下标就可以不用+1*/
{
	for (int i = 0; i <length; ++i)
	{
		if (*(data + i) == e)  //查找线性表中有没有跟e相等的元素
			return i + 1;    /*把e相等的元素返回，因为线性表是从1开始的，数组的下标是0开始的，于是线性表第i个元素存储在
							   数组下标i-1的位置，返回的时候要加1*/
	}
	return 0;

}
void sqList::ClearList()   //将线性表的元素清空
{
	delete data;
	data = NULL; 
	length = 0;
}
//初始化线性表, 初始化线性表还可以使用构造函数初始化
bool sqList::InitList()
{
	data = new ElemType[MAXSIZE];   //先为线性表分配空间
	if (!data) //判断p是否分配到内存，    如没有， 则返回错误
	{
		cout << "没有分配到内存，请从新分配！" << endl;
		return false;
	}
	length =0;         //线性表当前初始化为0
	cout << "初始化的线性表的长度为：" << length << endl;
	return true;
}
//获得元素的操作,将线性表中第i个位置的元素的值返回给e
Status sqList::GetElem(int i, ElemType &e)
{
	if (length == 0 || i<1 || i>length)  //判断当前线性表是为为空、或者i益出就返回错误
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
	e = *(data + i - 1); //把第i个元素返回给e
	return true;
}
//插入元素，  在线性表中第i个位置之前插入新元素e
Status sqList::ListInsert(int i, ElemType e)
{
	int k;    //一个临时变量，用于作为后面for循环的迭代变量.
	if (length == MAXSIZE) //线性表已满
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
		
	if (i<1 || i>length + 1)     //当i不在范围益处的时候
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
	if (i <= length)    //若插入的数据不在表尾,若在表尾直接跳过if语句
	{
		for (k = length; k >= i; k--)  /*元素i及其后面的元素都往后移一下以腾出i处的空间存放要插入的元素,*/
			*(data + k) = *(data +k-1);  //就是data[k-1]，  就是把k-1的元素变成k的元素，相当于向后移动
	}
	*(data + i - 1) = e;  //将新元素插入
	length++;    //表长加1
	return true;
}

//删除元素线性表中第i个数据元素，并用e返回其值， 表长减一
Status sqList::ListDelete(int i, ElemType &e)
{
	int k;   //一个临时变量，用于作为后面for循环的迭代变量.
	if (length == 0)     //线性表为空时
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
	if (i<1 || i>length)       //删除的位置不正确
	{
		cout << "错误，查找位置非法！" << endl;
		return false;
	}
	e = *(data + i - 1);   //取出要删除的元素
	if (i<length)     //如果要删除的不是最后位置
	{
		for (k = i; k<length; k++)     //将删除位置后的元素向前移动，  要删除的位置不能大于表长
			*(data + k-1) = *(data + k);  
	}
	length--;    //表长减一
	return true;
}
int main()
{
	sqList sq1;
	sq1.InitList();   //初始化线性表
	sq1.ListInsert(1, 5);
	sq1.ListInsert(2, 8);
	sq1.ListInsert(3, 2);
	sq1.ListInsert(4, 6);
	sq1.ListInsert(5, 15);
	sq1.ListInsert(6, 10);
	sq1.ListInsert(6, 2);
	cout << "插入值后，表的当前长度为：" << sq1.ListLength() << "\n\n";

	for (int i = 0; i < sq1.ListLength(); ++i)
	{
		int e=0; //表示要输出的元素
		sq1.GetElem(i + 1, e);
		cout << "表中第" << (i + 1) << "个元素为" << e << "\n";
	}
	cout << endl;
	//删除数据
	int deleteLocation = 0;
	cout << "请输入要删除的元素的位置：";
	cin >> deleteLocation;    //要删除的位置
	int deleteElement = 0;   //要删除的元素
	sq1.ListDelete(deleteLocation, deleteElement);
	cout << "删除了表中第" << deleteLocation << "个元素，该元素为：" << deleteElement << "\n\n";
	
	//输出删除后表中的数据
	for (int i = 0; i < sq1.ListLength(); ++i)
	{
		int e(0);
		sq1.GetElem(i + 1, e);
		cout << "删除后的表中第" << (i + 1) << "个元素为" << e << "\n";
	}
	cout << endl;
	//查找表中的数据
	int searchElement=0;
	cout << "请输入要查找的元素的值：";
	cin >> searchElement;
	cout << endl;
	int searchLocation = sq1.LocateElem(searchElement);
	if (!searchLocation)
	{
		cout << "当前表中无此元素" << endl;
	}
	else
		cout << "所要查找的元素位于表中第" << searchLocation << "个位置" << endl;
	cout << endl;

	//清空表
	sq1.ClearList();
	//判断表是否为空
	if (sq1.ListEmpty())
	{
		cout << "当前表为空表！" << endl;
	}
	else
		cout << "当前表非空！" << endl;
	cout << endl;
	//销毁链表
	sq1.DestroyList();

	cout << endl;
	system("pause");
	return 0;
}
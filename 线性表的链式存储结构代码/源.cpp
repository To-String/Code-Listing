#include <iostream>
using namespace std;

#define ERROR 1
#define OK 0
typedef bool Status;
typedef int ElemType;

//定义单链表类
class ChainList
{
public:
	//定义结点
	struct Node
	{
		ElemType m_data;     //数据域
		Node *m_next;   //指针域
	};
public:
	ChainList();  //构造函数用来初始化单链表的
	~ChainList();  //析构函数用来释放内存
	void creatList(ElemType *datas, ElemType length);//创建长度为length的链表，数据通过数组指定，这里采用尾插法
	Status listEmpty();//判断是否为空表

	void clearList();//  清空单链表的数据
	Status getElemAt(ElemType location, ElemType &elemOut);//获取元素
	Status locateElemAt(ElemType &location, ElemType element);//查找相等元素的索引位置

	Status listInsertAt(ElemType location, ElemType element);//插入元素
	Status listRemoveAt(ElemType location, ElemType &elemOut);//删除元素
	ElemType listLength()const;//返回线性表的长度
private:
	Node *m_heap;//头结点
};

//实现类chainList中各成员函数
ChainList::ChainList()
{
	m_heap = new Node;//给指针分配内存
	m_heap->m_next = NULL;
	m_heap->m_data = 0;
}

ChainList::~ChainList()
{
	delete m_heap;
}

void ChainList::creatList(ElemType *datas, ElemType length)  //创建长度为length的链表，数据通过数组指定，这里采用尾插法
{
	m_heap->m_data = length;  //头结点中的数据存储表长
	Node *m = m_heap;   //把头结点变成m
	for (int i = 0; i < length; i++)  //当 i还没有超过单链表的长度就循环继续
	{
		Node *n = new Node; //为每个新节点分配空间 
		n->m_data = datas[i];  //把每个输入的值存储到相应的节点

		m->m_next = n;  //把新节点n变成头结点m的后继节点（将表尾终端节点的指针指向新节点）
		m =n;  // 又把头结点的后继节点变成m(可以说是第一个节点，但是会随着循环而变动，)
	}
	m->m_next = NULL;   //表示当前链表结束

}

Status ChainList::listEmpty()   //判断是否为空表
{
	return (m_heap->m_data == 0 && m_heap->m_next == NULL);
}

void ChainList::clearList()    //清空链表
{
	Node *m = m_heap->m_next;  //把头节点的后继节点变成m
	while (m != NULL)   //当还有节点存在时，就循环继续
	{
		Node *n = m->m_next;  //然后把m的后继节点变成n
		delete m;   //删除第一个节点，每循环一次都删除第一个节点
		m = n;  //然后把n变成m， n就变成了第一个节点
	}
	m_heap->m_next = NULL;   //头结点指向的第一个结点清空
	m_heap->m_data = 0;      //头结点记录表长度，清零
}

Status ChainList::getElemAt(ElemType location, ElemType &elemOut)  //获得元素的操作,将线性表中第location个位置的元素的值返回给element
{
	
	Node *q;    //声明一个新节点q
	q = m_heap->m_next;    //让q指向链表的第一个节点
	if (location == 0)  //当查找的位置不合法时，就返回false
	{
		return ERROR;
	}
	int j = 1;  //从一个节点开始循环遍历，就是当前位置
	while (q && j < location)  //当前位置不是我们要找的元素的位置时，循环继续
	{                         /*当p还没有为空时， 当前的位置已经超过了要查找的位置，直接退出循环*/

		q = q->m_next;  //让q指向下一个节点
		j++;       //每循环一次当前位置都往后移动一位
	}
	if (!q || location > j)//P还没有指向空，当当前的位置已经超过了要找的位置，但还是没有找到，就返回错误
	{
		return ERROR;   //查找的元素不存在 
	}
	elemOut = q->m_data;   //取第i个元素的数据
	return OK;
}


Status ChainList::locateElemAt(ElemType &location, ElemType element)/*在线性表中的第location位置查找与element相等的元素，
													  返回第一个与element相等元素在线性表中的下标，否则，返回0*/
{
	Node *q = m_heap->m_next;  //把p的后继节点变成q
	int searchLocation=0;
	while (q != NULL)   //当q不为空时就继续循环
	{
		++searchLocation;
		if (q->m_data == element)//如果要查找的元素刚好就在q的数据域就退出循环
			break;            //q是会随着循环而变动的
		q = q->m_next;  //否则每次循环都把q的后继节点变成q，继续下一次的循环
	}
	if (q == NULL)   //当q为空时，就返回错误
	{
		return ERROR;
	}
	location = searchLocation;  //把要查找的元素的值扥位置用location返回给调用者
	return OK;
}

Status ChainList::listInsertAt(ElemType location, ElemType element)   //插入元素，  在线性表中第location个位置之前插入新元素element
{
	
	Node *q;  
	q = m_heap;    //把q变成头结点指针
	int j = 1;    //从一个节点开始循环遍历，就是当前位置
	while (q && j < location) //当前位置不是我们要找的元素的位置时，循环继续
	{                       //当q还没有为空时， 当前的位置已经超过了要查找的位置，直接退出循环
		q = q->m_next;   //q的指针向后移动不断指向下一个节点
		++j;
	}
	if (!q || location < j) //P还没有指向空，当当前的位置已经超过了要找的位置，但还是没有找到，就返回错误
	{
		return ERROR;   //说明要插入的第i个位置不存在
	}

	Node *s = new Node;  //生成一个新的节点
	s->m_data = element;     //把新元素e赋给s数据域
	s->m_next = q->m_next;  //将q的后继节点变成s的后继节点
	q->m_next = s;            //将s变成q的后继节点
	m_heap->m_data = m_heap->m_data+2;     //线性表的长度每次添加2
	return OK;
}

Status ChainList::listRemoveAt(ElemType location, ElemType &elemOut)   // 删除操作，删除线性表中第location个元素，然后用element返回
{
	
	Node *s, *q;
	int j = 1;
	s = m_heap;
	while (s->m_next && j < location)
	{                    //当p的后继节点还没有指向空时， 当前的位置已经超过了要查找的位置，直接退出循环
		s = s->m_next;  //s的指针向后移动不断指向下一个节点
		++j;
	}
	if (!(s->m_next) || j > location)  /*当p的后继节点还没有指向空时，	
									   当当前的位置已经超过了要找的位置，但还是没有找到，就返回错误*/
	{
		return ERROR;//第i个元素不存在
	}
	q = s->m_next;   //将s的后继节点变成q
	s->m_next = q->m_next;    //再把q的后继节点变成s的后继节点
	elemOut = q->m_data;  //将q节点的数据给element
	delete q;   //让系统回收此节点，释放内存
	m_heap->m_data -=2;   //每删除一个节点，线性表的长度少2
	return OK;
	
}

inline int ChainList::listLength()const  //返回线性表的长度
{
	return m_heap->m_data;   //p->data  表示的是头结点的数据域，存储的是单链表的长度
}

int main()
{
	ChainList *myChainList = new ChainList;  //创建一个对象,自动调用构造函数完成对单链表的初始化

	//开始创建链表
	int myLength=0;
	cout << "想创建多少数据的链表？";   
	cin >> myLength;
	int *myDatas = new int[myLength];   //为要创建的单链表数据分配空间，然后把分配的空间的地址赋给了myDatas
	cout << "请依次输入这" << myLength << "个数据，中间以回车符隔开：" << endl;
	for (int i = 0; i<myLength; i++)
	{
		cin >> myDatas[i];  //输入要存储的数据的值
	}
	myChainList->creatList(myDatas, myLength);
	cout << endl;
	//输出新创建链表中的值
	cout << "新建链表长度为" << myChainList->listLength() << ",表中数据为：" << endl;
	for (int i = 0; i<myLength; i++)
	{
		cout << myDatas[i] << " ";
	}
	cout << "\n\n";

	//读取链表中的值
	int readLocation=0;
	int readElement=0;
	cout << "请输入要获得数据在链表中的位置：";
	cin >> readLocation;
	if (myChainList->getElemAt(readLocation, readElement))
	{
		cout << "链表中第" << readLocation << "个数据为：" << readElement << "\n" << endl;
	}
	else
		cout << "查找的位置不合法！" << "\n" << endl;

	//查找某一元素是否位于链表中
	int findElement=0;
	int findLocation=0;
	cout << "请输入要查找的元素：";
	cin >> findElement;
	if (myChainList->locateElemAt(findLocation, findElement))
	{
		cout << "找到了元素" << findElement << "，其在链表中的索引值为：" << findLocation << "\n" << endl;
	}
	else
		cout << "链表中不存在所需找的值！" << "\n" << endl;

	//向链表中插入值
	int insertLocation=0;
	int insertElement=0;
	cout << "请输入要插入数据的位置：";
	cin >> insertLocation;
	cout << "请输入要插入的数据的值：";
	cin >> insertElement;
	cout << endl;
	if (myChainList->listInsertAt(insertLocation, insertElement))
	{
		cout << "插入数据成功！插入后，链表中剩余数据值为：" <<endl;
		for (int i =1; i < myChainList->listLength();++i)
		{
			int localElement=0;
			myChainList->getElemAt(i, localElement);
			cout << localElement << " ";
		}
		cout << endl << endl;
	}
	else
		cout << "数据插入失败,插入的位置不合理！" << "\n" << endl;

	//从链表中删除数据
	int deleteLocation=0;
	int deleteElement=0;
	cout << "请输入要删除数据第几个位置：";
	cin >> deleteLocation;
	if (myChainList->listRemoveAt(deleteLocation, deleteElement))
	{
		cout << "数据删除成功！删除数据后，链表中剩余数据值为：" << endl;
		for (int i = 0; i < myChainList->listLength(); i++)
		{
			int localElement=0;
			myChainList->getElemAt(i + 1, localElement);
			cout << localElement << " ";
		}
		cout << endl << endl;
	}
	else
		cout << "数据删除失败，删除的位置不合理！" << "\n" << endl;

	//将链表清空
	myChainList->clearList();

	//检查链表是否为空
	if (myChainList->listEmpty())
	{
		cout << "链表已清空！" << endl;
	}
	else
		cout << "链表尚未清空！" << endl;
	cout << endl;

	delete myDatas;  //释放主函数中的MyData分配的内存
	delete myChainList; //释放主函数中myChainList分配的内存
	myDatas = NULL; //怕对已经释放的内存在进行解引用，分别对他们指向的堆内存赋值为NULL，释放内存后也不能在对它们进行delete
	myChainList = NULL;

	cout << endl;
	system("pause");
	return 0;
}

//树的双亲表示法结点结构定义
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode   //结点结构
{
	TElemType data; //表示结点的数据域
	int parent;  //表示结点的指针域， 表示的是该结点的双亲在数组中的下标
}PTNode;
typedef struct  //树的结构
{
	PTNode node[MAX_TREE_SIZE];  //  结点数组，存放数据
	int r, n;  //根的位置和节点数
};

//孩子表示法的结点结构定义
#define MAX_TREE_SIZE 100
typedef struct CTNode //孩子结点
{
	int child;  //声明的是用来存储某节点的最左边的孩子的在数组中的下标
	struct CTNode *next; //是指向某一个节点的下一个孩子结点的指针
}*ChildPtr;
typedef struct   //表头结构
{
	TElemType data;  //用来存储结点的数据信息
	ChildPtr firstchild;//用来存储某结点孩子链表的头指针
}CTBox;
typedef struct   // 树结构
{
	CTBox nodes[MAX_TREE_SIZE];  //结点数组
	int r, n;  //根的位置和结点数
};

//树的孩子兄弟表示法
typedef  struct CSNode
{
	TElemType data;  //存储的是该结点的数据信息
	struct CSNode *firstchild;//该结点分别存储的是某结点的第一个孩子的结点的存储地址
	struct CSNode *rightsib;//存储的是某结点的右兄弟结点的存储地址
};
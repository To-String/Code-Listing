//����˫�ױ�ʾ�����ṹ����
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode   //���ṹ
{
	TElemType data; //��ʾ����������
	int parent;  //��ʾ����ָ���� ��ʾ���Ǹý���˫���������е��±�
}PTNode;
typedef struct  //���Ľṹ
{
	PTNode node[MAX_TREE_SIZE];  //  ������飬�������
	int r, n;  //����λ�úͽڵ���
};

//���ӱ�ʾ���Ľ��ṹ����
#define MAX_TREE_SIZE 100
typedef struct CTNode //���ӽ��
{
	int child;  //�������������洢ĳ�ڵ������ߵĺ��ӵ��������е��±�
	struct CTNode *next; //��ָ��ĳһ���ڵ����һ�����ӽ���ָ��
}*ChildPtr;
typedef struct   //��ͷ�ṹ
{
	TElemType data;  //�����洢����������Ϣ
	ChildPtr firstchild;//�����洢ĳ��㺢�������ͷָ��
}CTBox;
typedef struct   // ���ṹ
{
	CTBox nodes[MAX_TREE_SIZE];  //�������
	int r, n;  //����λ�úͽ����
};

//���ĺ����ֵܱ�ʾ��
typedef  struct CSNode
{
	TElemType data;  //�洢���Ǹý���������Ϣ
	struct CSNode *firstchild;//�ý��ֱ�洢����ĳ���ĵ�һ�����ӵĽ��Ĵ洢��ַ
	struct CSNode *rightsib;//�洢����ĳ�������ֵܽ��Ĵ洢��ַ
};
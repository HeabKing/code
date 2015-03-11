// �����ϰ 17.12
#ifndef TREE_H
#define TREE_H
#define MAXITEMS 1000  // ���б���������Ŀ��Ŀ
#define SLEN 81  // ���ʵ���󳤶�
//=============================================
// ʹ��֮ǰ��typedef��Item
typedef struct item
{
	char wrd[SLEN];
}Item;
//=============================================

typedef struct node
{
	Item item;
	int count;  // ���ʳ��ֵĴ���
	struct node * left;
	struct node * right;
}Node;

typedef struct tree
{
	int size;  // ���б������Ŀ����
	Node * root;
}Tree;

void Ini(Tree * pt);
inline bool TreeIsFull(const Tree * pt){return pt->size == MAXITEMS;}
inline bool TreeIsEmpty(const Tree * pt){return pt->size == 0;}
inline int TreeItemCount(const Tree * pt){return pt->size;}
bool AddItem(const Item * pi, Tree * ptree);
bool DeleteItem(Item * pi, Tree * ptree);
Node * IsInTree(const Item * pi, const Tree * ptree);  // NULL ���ǲ���������
void Travel(const Tree * ptree, void (*pfun)(Node *));
void DeleteAll(Tree * ptree);

#endif
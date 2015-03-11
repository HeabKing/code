// �����嵥 17.10
#ifndef _ercharshu_h_
#define _ercharshu_h_
#define MAXITEM 10  // ���������ɵ������Ŀ����
typedef struct item
{
	char petname[20];
	char petkind[20];
}Item;
typedef struct node
{
	Item item;
	struct node * left;
	struct node * right;
}Node;
typedef struct tree
{
	Node * root;
	int ct;
}Tree;

void Ini(Tree * ptree);
int TreeItemCount(const Tree * ptree);
bool TreeIsFull(const Tree * ptree);
bool TreeIsEmpty(const Tree * ptree);
bool AddItem(Tree * ptree, const Item * pitem);  // const˵������ptreeָ���Tree��������ݸ��ڵ㲻�ܸ�, ������ӵ�ʱ��Ҳ������Ӹ��ڵ�, ������ӵ�ʱ��const���ǲ��ܼ���
bool DeleteItem(Tree * ptree, const Item * pitem);
bool IsInTree(const Tree * ptree, const Item * pitem);
void Traverse(const Tree * ptree, void (*fun)(Item item));
void DeleteAll(Tree * ptree);

#endif
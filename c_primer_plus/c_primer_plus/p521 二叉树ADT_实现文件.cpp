// �����嵥 17.11
#include <stdio.h>
#include <stdlib.h>  // malloc() free()
#include <string.h>  // strcmp()
#include "p521 ������ADT.h"

typedef struct three
{
	Node * parent;
	Node * child;
	Node ** add;
}Three;

static Node * MakeNode(const Item * pitem);
static Th
	ree SeekItem(const Tree * ptree, const Item * pitem);
static int LeftOrRight(const Node * pnode, const Item * pitem);
static void DeleteNode(Node ** ppnode);
static void InOrder(const Node * root, void (*pfun)(Item item));
static void DeleteAllNodes(Node * pnode);

void Ini(Tree * ptree)
{
	ptree->ct = 0;
	ptree->root = NULL;
}

int TreeItemCount(const Tree * ptree)  // ���ﴫ�ݵ���Tree�ĵ�ַptree, ����һ��ֵ, ���������Ｔʹ��ptree�ı���Ҳ���ں����˳�ʱ��ԭ���ĵ�ַû���κ�Ӱ��
{
	return ptree->ct;
}

bool TreeIsEmpty(const Tree * ptree)
{
	return ptree->ct == 0;
}

bool TreeIsFull(const Tree * ptree)
{
	return ptree->ct == MAXITEM;
}

bool AddItem(Tree * ptree, const Item * pitem)
{
	if (TreeIsFull(ptree))
		return false;
	Node * temp;
	if ((temp = MakeNode(pitem)) == NULL)
	{
		fprintf(stderr, "�޷�Ϊ�½ڵ�����ڴ�!\n");
		return false;
	}
	Three three;
	three = SeekItem(ptree, pitem);
	if (three.child != NULL)
	{
		fprintf(stderr, "�Ѿ�������ͬ����Ŀ��\n");
		free(temp);
		return false;
	}
	*three.add = temp;  // ��ʹ�ǿ���Ҳ�ܼ���ȥ
	ptree->ct++;
	return true;
}

bool DeleteItem(Tree * ptree, const Item * pitem)
{
	Three look;
	look = SeekItem(ptree, pitem);
	if (look.child == NULL)  // û���ҵ���ɾ����Ŀ
		return false;
	if (look.parent == NULL)  // û�и���Ŀ���߸���Ŀ���Ǵ�ɾ����Ŀ
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)  // ��������
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->ct--;
	return true;
}

bool IsInTree(const Tree * ptree, const Item * pitem)
{
	return SeekItem(ptree, pitem).child != NULL;
}

void Traverse(const Tree * ptree, void (*pfun)(Item item))
{
	if (ptree == NULL)
		return;
	if (ptree->root != NULL)
	{
		InOrder(ptree->root, pfun);  // ������������֧��Ҫ�漰����������seekItem��ֻ�漰һ����֧, �����õݹ�ʵ�ַ���
			// ����ptree�õ���root, �����������õ�left��right, ����Ҫ���·�һ�������ܿ������ϵĲ�һ��
	}
}

void DeleteAll(Tree * ptree)
{
	if (ptree->root != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->ct = 0;
}

static Node * MakeNode(const Item * pitem)
{
	Node * temp;
	temp = (Node *)malloc(sizeof(Node));
	if (temp != NULL)
	{
		temp->item = *pitem;
		temp->left = NULL;
		temp->right = NULL;
	}
	return temp;
}

//==============================================================
// 1. parent == NULL child == NULL (add != NULL) ��ʱû�и��ڵ�
// 2. parent == NULL chile != NULL (add != NULL) ��ʱ�и��ڵ� ���Ҹ��ڵ������Ŀ������ͬ��
// 3. parent != NULL child == NULL (add != NULL) ��ʱ�ҵ�����ӵ�λ��, addָ��������
// 4. (parent != NULL) child != NULL (add != NULL) ��ʱ������ͬ����Ŀ, childָ����ͬ��Ŀ
static Three SeekItem(const Tree * ptree, const Item * pitem)
{
	Three temp;
	temp.parent = NULL;
	temp.child = ptree->root;
	temp.add = (Node **)&ptree->root;  // ������һ������const�ķ���!!!!!!!!
	if (ptree->root == NULL)
		return temp;
	while (temp.child != NULL)
	{
		switch(LeftOrRight(temp.child, pitem))
		{
		case 1:   // ######### ����������1 �������ַ�'1' ##########
			temp.add = &temp.child->left;
			temp.parent = temp.child;
			temp.child = temp.child->left;
			break;
		case -1: 
			temp.add = &temp.child->right;
			temp.parent = temp.child;
			temp.child = temp.child->right;
			break;
		case 0:
			return temp;  // ����������޷���ʾ��Ŀ��ͬ��!!!!!!!!!!!!!!!!
			// ��һ��ѭ������case '0' �Ļ����������2
		}
	}
	return temp;
}

static int LeftOrRight(const Node * pnode, const Item * pitem)
{
	int cpy, cpy1;
	if ((cpy = strcmp(pnode->item.petname, pitem->petname)) > 0)
		return -1;
	if (cpy == 0 && ((cpy1 = strcmp(pnode->item.petkind, pitem->petkind)) > 0))
		return -1;
	if ((cpy == 0 && cpy1 < 0) || (cpy < 0))
		return 1;
	if (cpy == 0 && cpy1 == 0)
		return 0;
}

static void DeleteNode(Node ** ppnode)
{
	Node * temp;
	puts((*ppnode)->item.petname);
	if ((*ppnode)->left == NULL)  // ��ɾ��Ŀ��֧Ϊ��
	{
		temp = *ppnode;
		*ppnode = (*ppnode)->right;
		free(temp);
	}
	else if ((*ppnode)->right == NULL)  // ��ɾ��Ŀ��֧Ϊ��
	{
		temp = *ppnode;
		*ppnode = (*ppnode)->left;
		free(temp);
	}
	else  // ��ɾ��Ŀ����֧����Ϊ��
	{
		for (temp = (*ppnode)->left; temp->right != NULL;
			temp = temp->right)
			continue;
		temp->right = (*ppnode)->right;
		temp = *ppnode;
		*ppnode = (*ppnode)->left;
		free(temp);
	}
}

static void InOrder(const Node * pnode, void (*pfun)(Item item))
{
	if (pnode != NULL)
	{
		InOrder(pnode->left, pfun);
		(*pfun)(pnode->item);
		InOrder(pnode->right, pfun);
	}
}

static void DeleteAllNodes(Node * pnode)
{
	Node * temp;
	if (pnode != NULL)
	{
		temp = pnode->right;
		DeleteAllNodes(pnode->left);
		free(pnode);
		DeleteAllNodes(temp);
	}
}
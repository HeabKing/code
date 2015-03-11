// �����嵥 17.11
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p521������ADT.h"

// �ֲ��������Ͷ���
typedef struct pair
{
	Node * parent;
	Node * child;
}Pair;

// �ֲ�����ԭ��
static Node * MakeNode(const Item * pi);  // ����: ����һ���ڵ�  ����ǰ: �Ѿ��жϹ���Item�ܹ����뵽����, ����û����  ������: ����ɹ�������һ���ڵ�, �򷵻ؽڵ�ĵ�ַ, ���򷵻�NULL
static bool ToLeft(const Item * i1, const Item * i2);  // ����: �ж�i1����i2����֧������֧, �������֧����true, ���򷵻�false
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Node * new_node, Node * root);  // ����: ��һ���ڵ���뵽����
static void InOrder(const Node * root, void (*pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);  // 1. parent == NULL && child == NULL û�и��ڵ�   2. parent == p�� && child == p��->left / p��->right == NULl �ҵ���λ��, ֱ�����µ�ַ�滻NULL   3. parent == p�� && child == p��->left / p��->right != NULL �ҵ���ͬ��ͬ���, childָ��ķ�NULL����
static void DeleteNode(Node ** ptr);
static void DeleteAllNodes(Node * ptr);

void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	return ptree->root == NULL && ptree->size == 0;
}

bool TreeIsFull(const Tree * ptree)
{
	return ptree->size == MAXITEMS;
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
	Node * new_node;

	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;  // ��ǰ����
	}
	// �ж��µ�Item�Ƿ��ܹ����뵽����
	if (SeekItem(pi, ptree).child != NULL)  // �����λ����Ŀû�п�next���� (��ʱ����child��ʵ�������ֺ�������ͬ�Ľڵ�ĵ�ַ)
	{
		fprintf(stderr, "Attempted(δ���,\
			��ͼ��) to add duplicate(v.����,\
			ʹ�ӱ� n.����, ����Ʒ) item\n");
		return false;
	}
	// Ϊ�µ�Item����ڵ�
	new_node = MakeNode(pi);  // ָ���½ڵ�
	if (new_node == NULL)  // ���û�ܳɹ������ڴ�
	{
		fprintf(stderr, "Could't creat node.\n");
		return false;
	}
	// �ɹ�������һ���½ڵ�
	ptree->size++;
	// ��ʼ�ѽڵ�ӽ�����
	if (ptree->root == NULL)  // ���1: ��Ϊ����
		ptree->root = new_node;  // �½ڵ㼴Ϊ���ĸ��ڵ�
	else                    // ���2: ���ǿ�
		AddNode(new_node, ptree->root);  // Ϊ�½ڵ�Ѱ�Һ��ʵ�λ��, ���ӽ�ȥ
	return true;  // �ɹ�����
}

bool IsIntree(const Item * pi, const Tree * ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)  // û���ҵ�Ҫɾ������Ŀ
		return false;
	if (look.parent == NULL)  // ɾ������Ŀ
		DeleteNode(&ptree->root);  // ���ptree->root == NULL ��û�и���Ŀɾ��, ����ɾ������Ŀ   ???
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;

	return true;
}

void Traverse(const Tree * ptree, void (*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)  // *pi���ں���Ŀ�Ƚ���ȷ���Ǹ������߻���������
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
		return look;  // ��ǰ����
	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))  // ���Ӧ��������
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))  // �����������
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else  // ���ǰ�����������������Ļ�, �ض�����ȵ����
			break;  // ��������, look.child��Ŀ��ڵ�ĵ�ַ
		// ���ﻹ������һ����� parent == NULL child != NULL ���ڵ���Ŀ����ͬ
	}
	return look;  // �ɹ�����
}

static bool ToLeft(const Item * i1, const Item * i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)  // ���Ŀ����Ŀ�����ֱ�������ĿAsciiС
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0)  // ���������ͬ�ͱȽ�����
		return true;
	else
		return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}

static Node * MakeNode(const Item * pi)
{
	Node * new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)  // ����ɹ��������ڴ�
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;  // ��ʹû�ܹ��ɹ����䷵����NULLҲ����ȥ, �õ��ú������ж�Ȼ�󱨴�
}

static void AddNode(Node * new_node, Node * root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)  // ������
			root->left = new_node;  // ��˰ѽڵ���ӵ��˴�
		else
			AddNode(new_node, root->left);  // ����ݹ鴦�������
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else  // ��Ӧ�ú�����ͬ����Ŀ
	{
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static void DeleteNode(Node ** ptr)  // ptr��ָ��Ŀ��ڵ�ĸ��ڵ�ָ���Ա��ַ
{
	Node * temp;
	puts((*ptr)->item.petname);
	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else  // ��ɾ���ڵ��������ӽڵ�
	{
		for (temp = (*ptr)->left; temp->right != NULL;
			temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

static void InOrder(const Node * root, void (*pfun)(Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Node * root)
{
	Node * pright;

	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}
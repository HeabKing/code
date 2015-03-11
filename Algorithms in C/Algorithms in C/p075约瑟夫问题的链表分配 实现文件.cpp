#include <stdlib.h>
#include "p075Լɪ��������������.h"

	// ����һ��Node����, ǰһ��Node��nextָ���һ��

link freeList;
void initNodes(int N)
{
	int i;
	freeList = (link)malloc((N + 1) * sizeof(*freeList));
	for (i = 0; i < N; i++)	// ��������ϵ�N+1�ĳ���N
		freeList[i].next = &freeList[i+1];
	freeList[N].next = NULL;
}

	// ȡ����ʼ������ڶ���node, ��ֵΪ����, nextָ���Լ�
link newNode(int i)
{
	link x = deleteNext(freeList);
	x->item = i;
	x->next = x;
	return x;
}

	// ɾ������linkָ��Ľڵ����һ���ڵ�, ���������ɾ���Ľڵ㷵��
link deleteNext(link Current)
{
	link Next = Current->next;
	Current->next = Next->next;
	return Next;
}

	// �ڵ�һ������linkָ���node��߼���ڶ�������linkָ���node
void insertNext(link Prev, link insert)
{
	insert->next = Prev->next;
	Prev->next = insert;
}

	// ���ز���linkָ���node��ߵ�node
link Next(link x)
{
	return x->next;
}

	// ���ز���linkָ��node��itemֵ
int Item(link x)
{
	return x->item;
}

	// ����ɾ����node��freeList����
void freeNode(link x)
{
	insertNext(freeList, x);
}
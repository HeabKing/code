#include "p075 Լɪ��������������.h"
#include <stdlib.h>

	// ���������ʼ��:
	//		. �����������Լ����ƽڵ�
	//		. ��������ı�ͷ����Ӧ�ÿ��Ա�������������
	//		. ���������ǰnode�����ź�node
	//		. ��������������߼�node��NULL

link freeList;	// ��������ͷ����, �����к�������
void initNode(int n)
{
	freeList = (link)malloc(sizeof(*freeList) * (n + 1));	// �����һ�����ƽڵ�
	for (int i = 0; i < n; i++)
	{
		freeList[i].item = -1;
		freeList[i].next = &freeList[i+1];
	}
	freeList[n].item = -1;
	freeList[n].next = NULL;
}

	// ��ȡһ��node:
	//		. �ӿ��������ƽڵ����ó�һ��

link newNode(Item item)
{
	link CN = deleteNext(freeList);

	CN->item		= item;
	CN->next		= NULL;
	return CN;
}

	// freeNode:
	//		. ��һ��node���յ�����������
	//		. �����λ��Ϊ�ƽڵ���

void freeNode(link CN)
{
	link NN = freeList->next;
	freeList->next = CN;
	CN->next = NN;
}

	// insertNext:
	//		. Ϊ����1��node������һ������2node
void insertNode(link CN, link NN)
{
	NN->next = CN->next;
	CN->next = NN;
}

link deleteNext(link CN)
{
	link NN = CN->next;
	CN->next = NN->next;
	return NN;
}
#include "p075 Լɪ��������������.h"
#include <stdio.h>
#define N  9
#define M  5
int main(void)
{
		// ΪN����Ŀ�����ڴ�, ���ɿ�������
	initNode(N);

		// ȡ��һ��node, ��ֵΪ1, node��nextΪNULL
	link head = newNode(1);

		// ������һ��ѭ������
	link CN;
	link PN = head;
	for (int i = 2; i <= N; i++)
	{
		CN = newNode(i);
		insertNode(PN, CN);
		PN = CN;
	}
	CN->next = head;	// �γ�ѭ������
	link Last = CN;

		// ������������

	CN = head;
	while (CN->next != head)
	{
		printf("%d ", CN->item);
		CN = CN->next;
	}
	printf("%d \n", CN->item);

	CN = Last;
	while (CN != CN->next)
	{
		for (int i = 1; i < M; i++)
			CN = CN->next;
		printf("%d\n", CN->next->item);
		freeNode(deleteNext(CN));
	}

	printf("\n\n%d \n", CN->item);

	return 0;
}
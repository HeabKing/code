#include <stdio.h>
#include "p075Լɪ��������������.h"

int main(void)
{
	int i, N, M;

	printf_s("N: ");
	scanf_s ("%d", &N);
	printf_s("M: ");
	scanf_s ("%d", &M);

	Node t, x;

		// ΪN����Ŀ�����ڴ�, ����node����;
	initNodes(N);

		// ȡ��һ��node, ��ֵΪ1, ֻ��һ��node��ѭ������
	link head = newNode(1);

		// ������һ��ѭ������
	x = head;
	for (i = 2; i <= N; i++)
	{
		t = newNode(i);
		insertNext(x, t);
		x = t;
	}	// ��ʱxָ�����һ��node, ��ѭ����x->next����head

		// ������������
	link Current = head;
	while (Current->next != head)
	{
		printf("%d ", Current->item);
		Current = Current->next;
	}
	printf("%d \n", Current->item);

	while (x != Next(x))
	{
		for (i = 1; i < M; i++)
			x = Next(x);
		freeNode(deleteNext(x));
	}
	printf("%d\n", Item(x));

	return 0;
}
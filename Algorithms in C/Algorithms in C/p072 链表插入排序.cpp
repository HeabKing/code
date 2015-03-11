#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node *link;
struct node
{
	int		iItem;
	link	next;
};

link reverse(link);

int main(void)
{
	srand((unsigned long)time(0));
	int N = 100;	// ��Ŀ����

		// ����һ������, �ں���������

	link Current	= (link)malloc(sizeof (*Current));	// �ƽڵ�
	link head		= Current;	// head�����ƽڵ�
	Current->iItem = -1;
	Current->next	= NULL;
	for (int i = 0; i < N; i++)
	{
		link Prev	= Current;
		Current		= (link)malloc(sizeof (*Current));
		Current->iItem = rand() % 100;
		Current->next	= NULL;
		Prev->next	= Current;
	}

		// ���δ����״̬

	Current = head->next;	// ���ƽڵ��߿�ʼ���
	while (Current != NULL)
	{
		printf("%d ", Current->iItem);
		Current = Current->next;
	}

		 // ��ʼ���в�������

	link head2		= (link)malloc(sizeof(*head2));
	head2->next		= NULL;
	head2->iItem	= -2;

	link Next;
	for (Current = head->next, head->next = NULL; Current != NULL; Current = Next)
	{
		Next = Current->next;

		link Current2 = head2;
		for (; Current2->next != NULL; Current2 = Current2->next)
			if (Current2->next->iItem > Current->iItem)
				break;
		Current->next = Current2->next;
		Current2->next = Current;
	}

		// ��������״̬

	printf("\n\n\n");
	link Current2 = head2->next;	// ���ƽڵ��߿�ʼ���
	while (Current2 != NULL)
	{
		static int i = 0;
		if (i++ == 100)
			break;
		printf("%d ", Current2->iItem);
		Current2 = Current2->next;
	}

		// ��������

	printf("\n\n\n");
	Current2 = reverse(head2->next);	// ���ƽڵ��߿�ʼ���
	while (Current2 != NULL)
	{
		static int i = 0;
		if (i++ == 100)
			break;
		printf("%d ", Current2->iItem);
		Current2 = Current2->next;
	}

	return 0;
}

link reverse(link CN)
{
	link NN, PN = NULL;	// NULLҲ���Ե���һ��node, һ��û��item��node
	while (CN != NULL)
	{
		NN			= CN->next;
		CN->next	= PN;
		PN			= CN;
		CN			= NN;
	}
	return PN;
}
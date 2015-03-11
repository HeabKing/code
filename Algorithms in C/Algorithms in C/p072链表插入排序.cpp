#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct node *link;
typedef int			item;
struct node
{
	item Item;
	link next;
};

	// ��������
link reverse(link);	// ����βnode��ָ��

int main(void)
{
	struct node headin, headout;	// headin, ���������ƽڵ�, ����δ��������, headout, ��������ƽڵ�, ������������;
	int i;
	int N;	// Ҫ��������������

		// ������Ŀ����

	printf_s("������Ŀ����: ");
	scanf_s("%d", &N);

		// �������ֵ, ������headin����

	link currentin = &headin;	// "��ǰ"�����ڵ�Ϊ������ƽڵ�
	srand((unsigned long)time(0));
	for (i = 0; i < N; i++)
	{
		currentin->next = (link)malloc(sizeof(node));

			// "��ǰ"�����ڵ�Ϊ�½ڵ�
		currentin = currentin->next;
		currentin->next = NULL;
		currentin->Item = rand() % 1000;
	}

		// ���headin��������

	currentin = headin.next;	// "��ǰ"Ϊ�����ƽڵ��ߵ�һ����
	for (i = 0; i < N; i++)
	{
		printf ("%d ", currentin->Item);
		currentin = currentin->next;
	}

		// ��headin����nodeһ��һ���Ĳ��뵽headout����

	link nextin;
	link currentout;
	headout.next = NULL;
	for (currentin = headin.next, headin.next = NULL; currentin != NULL; currentin = nextin)	// һֱѭ����������û�����ݽڵ�
	{
		nextin = currentin->next;

			// Ѱ��headout�к��ʵĲ���λ��
		for (currentout = &headout; currentout->next != NULL; currentout = currentout->next)
			if (currentout->next->Item > currentin->Item)
				break;

			// ���в���
		currentin->next = currentout->next;
		currentout->next = currentin;
	}

		// ���headout��

	printf("\n\n\n\n");
	currentout = headout.next;
	for (i = 0; i < N; i++)
	{
		printf ("%d ", currentout->Item);
		currentout = currentout->next;
	}

		// ��������

	printf("\n\n\n\n");
	currentout = reverse(&headout);;
	for (i = 0; i < N; i++)
	{
		printf ("%d ", currentout->Item);
		currentout = currentout->next;
	}

	return 0;
}

link reverse(link li)
{
	link Current, Next, Prev;
	
	Prev		= NULL;
	Current		= li;

	while (Current != NULL)
	{
			// ����"��һ��"�ڵ�
		Next = Current->next;	// û���������ʼ��Next�ǿ��ǵ�Current����û��node�����, �������ʼ������, ֻ����Current != NULL������²���Next�Ĵ���;

			// ���ӵ���
		Current->next = Prev;
		
			// ˢ��"��һ��"��"��ǰ"�ڵ�
		Prev	= Current;
		Current	= Next;
	}

	return Prev;
}
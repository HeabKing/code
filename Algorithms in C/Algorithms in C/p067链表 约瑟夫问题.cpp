#include <stdio.h>
#include <stdlib.h>
#define ����ʵ��

#if defined ����ʵ��
typedef struct node * link;
struct node
{ 
	int item; 
	link next;
};

int main(void)
{
	int i, N, M;

	printf("��ʼԲ������: ");
	scanf_s("%d", &N);
	printf("Բ��ָ��ƫ����: ");
	scanf_s("%d", &M);

		// ������һ���ڵ�
	link t = (link)malloc(sizeof *t);
	link x = t;

		// ����һ���ڵ㸳ֵ
	t->item = 1;	// 1 �������ǵ�һ���ڵ�
	t->next = t;	// �ڵ�ָ���Լ�

		// ����ʣ�µĽڵ�, ����һ��Բ��
	for (i = 2; i <= N; i++)
	{
		x = (x->next = (link)malloc(sizeof *x));
		x->item = i; 
		x->next = t;
	}

		// һֱѭ����ֻʣһ���ڵ�
	while (x != x->next)
	{
		for (i = 1; i < M; i++)
			x = x->next;
		x->next = x->next->next;
		N--;

		//	// �����ǰ״̬
		//link temp = x;
		//for (int i = 0; i < N; i++)
		//{
		//	printf("%d ", temp->item);
		//	temp = temp->next;
		//}
		//printf("\n");
	}
	printf("%d\n", x->item);
	return 0;
}

#else

#include <stdio.h>

int main(void)
{
	int i, N, M;

	printf("��ʼԲ������: ");
	scanf_s("%d", &N);
	printf("Բ��ָ��ƫ����: ");
	scanf_s("%d", &M);

	int *item = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		item[i] = i + 1;
	item[N-1] = 0;

	while (item[i])
	{

	}

	return 0;
}

#endif
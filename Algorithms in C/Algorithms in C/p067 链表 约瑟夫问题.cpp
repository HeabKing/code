#include <stdio.h>
#include <stdlib.h>

typedef struct node * link;
typedef int	item;

struct node
{
	item Item;
	link next;
};

int main(void)
{
	int M, N;

	printf("����: ");
	scanf("%d", &N);
	printf("ƫ����: ");
	scanf("%d", &M);

		// ������һ���ڵ�, �Ա���ѭ����ʹ��
	link headnode	= (link)malloc(sizeof(node));
	headnode->Item = 1;
	headnode->next = headnode;	// �γ�ѭ������

		// ��ʱ����ָ������ڵ�(��һ���ڵ�);
	link temp		= headnode;

		// ����ʣ��ڵ�
	for (int i = 2; i <= N; i++)
	{
			// �����ڵ�nextָ���½ڵ�
		temp->next	= (link)malloc(sizeof(node));

			// �½ڵ��Ϊ�����ڵ�
		temp		= temp->next;

			// �Բ����ڵ���и�ֵ
		temp->Item	= i;
		temp->next	= headnode;	// �γ�ѭ������
	}

		// ������߼���������΢�е㲻ͬ, ����temp��ʼָ�����ͷ, ������xָ�����β
	temp = headnode;
	while (temp->next != temp)
	{
		for (int i = 1; i < M - 1; i++)
			temp = temp->next;
		temp->next = temp->next->next;	// �Ƴ�Ŀ��ڵ�
		temp = temp->next;	// ָ���Ƴ������һ��node
		N--;
	}
	printf("%d", temp->Item);

	return 0;
}
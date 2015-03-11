// �����嵥 17.2
#include <stdio.h>
#include <stdlib.h>  // malloc()
#include <string.h>  // strcpy()
#define TSIZE 75  // Movie title limit

struct film
{
	char title[TSIZE];
	int rating;
	struct film * next;
};

int main(void)
{
	struct film * head = NULL;  // ָ���һ���ṹ��ָ��
	struct film * prev, * current;  // prevָ����һ���ṹ��ָ��, currentָ������ṹ��ָ��
	char input[TSIZE];

	// �ռ����洢��Ϣ
	puts("Enter first movie title: ");
	while (gets(input) && input[0] != '\0')  // �������Ҫ�Ͳ�Ҫ��malloc����һ���µĶ�̬�ṹ, �����ȴ���һ������input
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (NULL == head)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Your rating<0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title(empty line to stop):");
		prev = current;
	}

	if (NULL == head)
		puts("No data entered.");
	else
		puts("Here is the movie list: ");
	current = head;  // ���ﲻֱ����head����linked list��Ϊ�˷�ֹhead��ֵ���ı�
	while (NULL != current)
	{
		printf("Movie: %s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}

	current = head;
	while(current != NULL)
	{
		struct film * temp;
		temp = current->next;
		free(current);
		current = temp;
	}

	puts("Bye!");

	return 0;
}
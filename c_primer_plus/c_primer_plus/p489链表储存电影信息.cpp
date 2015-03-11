// �����嵥 17.2
#include <stdio.h>
#include <stdlib.h>  // �ṩmalloc()ԭ��
#include <string.h>  // �ṩstrcpy()ԭ��
#define TSIZE 45     // Ƭ����������
struct film {
	char title[TSIZE];
	int rating;
	struct film * next;
};

int main (void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];

	// �ռ����洢��Ϣ
	puts ("Enter first movie title: ");
	while (gets (input) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc (sizeof (struct film)); //���malloc�ķ���ֵΪnull��ʾ���޷���ȡ�����ڴ�
		if (NULL == head)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy (current->title, input);
		puts ("Enter your rating <0 - 10>: ");
		scanf ("%d", &current->rating);
		while (getchar () != '\n')
			continue;
		puts ("Enter next movie title (empty line to stop): ");
		prev = current;
	}

	// ������Ӱ�б�
	if (NULL == head)
		puts ("No data entered. ");
	else
		puts ("Here is the movie list: ");
	current = head;
	while (NULL != current)
	{
		printf ("Movie: %s Rating: %d\n", current->title, current->rating);
		current = current->next;
	}

	// �������, �ͷŷ�����ڴ�
	current = head;
	while (current != NULL)
	{
		struct film * temp;
		temp = current ->next; // ��������д����!
		free (current);
		current = temp;
	}
	puts ("Bye!");

	return 0;
}
// 7-11 ��new��delete��̬�ڴ���䷽��,ʵ�ֶ�������Ŀ��������������
#include <stdlib.h>
#include <stdio.h>

void sortArray1 (int [], int);

int main (void)
{
	int num;
	int i;
	int * a;

	printf ("������Ҫ���������������Ŀ:\n");
	scanf_s ("%d", &num);
	//printf ("������Ҫ����ĸ���:\n");
	//scanf ("%d", &num);

	// ��̬���������ڴ�
	a = new int[num];
	if (NULL == a)
	{
		printf ("�ڴ����!");
		return 0;
	}

	printf ("������Ҫ���������:\n");
	for (i = 0; i < num; i++)
		scanf_s ("%d", &a[i]);

	sortArray1(a, num);

	for (i = 0; i < num; i++)
		printf (" %d ", a[i]);

	return 0;
}

void sortArray1 (int p[], int len)  // �˴���int p[]��ʵ�Ǹ���ֵַ
{
	for (int i = 0; i < len - 1; i++)
		for (int index = i + 1; index < len; index++)
			if (p[i] > p[index])
			{
				int hold = p[i];
				p[i] = p[index];
				p[index] = hold;
			}
}
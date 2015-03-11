// p177 ����ָ��ʵ��������                                             // ����ָ��ָ����Ǵ�����
#include <stdio.h>                                                       // ��ͨ����ָ��ָ��������ݴ洢��
#include <stdlib.h>

bool ascending (int, int);                         // �����жϺ���
bool decending (int, int);                        // �����жϺ���
void sortArray (int [], int, bool (*)(int, int));  // ������
void displayArray (int [], int);

int main (void)
{
	int * a;
	int i, num;

	// ����Ҫ�����������Ŀ
	printf ("������Ҫ�����������Ŀ:\n");
	scanf ("%d", &num);

	// ��̬�����ڴ�
	a = new int[num];
	if (NULL == a)
	{
		printf ("�ڴ����!");
		return 0;
	}

	// ���������������
	printf ("������Ҫ���������:\n");
	for (i = 0; i < num; i++)
		scanf ("%d", &a[i]);

	// ������������
	sortArray (a, num, ascending);

	// ���a�����Ľ��
	printf ("���������:\n");
	for (i = 0; i < num; i++)
		printf (" %d ", a[i]);
	printf ("\n");

	// ʹ��descending��a��������
	sortArray (a, num, decending);
	
	// ���a�����Ľ��
	printf ("���������:\n");
	for (i = 0; i < num; i++)
		printf (" %d ", a[i]);
	printf ("\n");

	// �ͷŶ�̬����Ŀռ�
	delete [] a;

	return 0;
}

bool ascending (int a, int b)
{
	return (a < b);
}

bool decending (int a, int b)
{
	return (a > b);
}

void sortArray (int b[], int len, bool (*compare) (int, int))
{
	for (int pass = 0; pass < len - 1; pass++)
		for (int i = pass + 1; i < len; i++)
			if (!(*compare)(b[pass], b[i])) 
			{
				int temp;
				temp = b[pass];
				b[pass] = b[i];
				b[i] = temp;
			}
}
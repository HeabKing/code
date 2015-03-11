// 7-10 ��malloc(��Ŷ���,��̬�ڴ�)��free��̬�ڴ���䷽��,ʵ�ֶ�������Ŀ��������������
#include <stdlib.h>
#include <stdio.h>

void sortArray (int[], int);  // ����������

int main (void)
{
	int * a;                               // aΪһ����ַ,Ϊ�±߰Ѷ�̬����������׵�ַ����a���̵�
	int i, num;

	// ����Ҫ�����������Ŀ
	printf ("������Ҫ���������������Ŀ:\n");
	scanf_s ("%d", &num);

	// ��̬��������,�������������
	a = (int * )malloc(sizeof(int) * num); // �˴��ǰ�����ڴ����a�����ǰ�����ڴ�ĵ�ַ����a
	if (NULL == a)
	{
		printf ("�ڴ����!");
		return 0;
	}

	// ���������������
	printf ("������Ҫ�������������:\n");
	for (i = 0; i < num; i++)	
		scanf ("%d", &a[i]);

	// ��������������
	sortArray(a, num);

	// ��������Ľ��
	printf ("����������:\n");
	for (i = 0; i < num; i++)
		printf (" %d ", a[i]);

	// �ͷŶ�̬����Ŀռ�
	free (a);
}

void sortArray (int a[], int len)
{
	for (int pass = 0; pass < len - 1; pass++) // �˴���ʼ��pass��ʱ�����������
		for (int i = pass + 1; i < len; i++)
			if(a[pass] > a[i])
			{
				int hold;
				hold = a[pass];
				a[pass] = a[i];
				a[i] = hold;
			}
}
// ָ�������   ָ��ӷ�            ��һ��ָ���1�Ľ���ǶԸ�ָ���1���洢��Ԫ
// c primer plus �����嵥 10.8 p254
// pnt_add.c -- ָ��ӷ�
#include <stdio.h>
#define SIZE 4
int main (void)
{
	short dates[SIZE];
	short * pti;  // ָ�������
	short index;
	double bills[SIZE];
	double * ptf;

	pti = dates;  // ������ĵ�ַ������ָ��
	ptf = bills;
	printf ("%23s %10s\n", "short", "double");     // ָ������ַ����Ĵ�С
	for (index = 0; index < SIZE; index++)
		printf ("pointers + %d: %10p %10p\n",
				index, pti + index, ptf + index);

	return 0;
}
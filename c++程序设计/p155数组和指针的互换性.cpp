// �� 7-3 �����ָ��Ļ�����ʾ��
#include <stdio.h>
#define SIZE 5

int main (void)
{
	int a[SIZE] = {0, 1, 2, 3, 4};
	int * aPtr = a;              // ����a���׵�ַ����ָ��aPtr
	int i;

	// ͨ�����������±��������
	for (i = 0; i < SIZE; i++)
		printf ("\na[%d] = %d", i, a[i]);

	// ͨ��ָ����±��������
	for (i = 0; i < SIZE; i++)
		printf ("\naPtr[%d] = %d", i, aPtr[i]);
	// ͨ��ָ���ƫ������������
	for (i = 0; i < SIZE; i++)
		printf ("\n*(aPtr + %d) = %d", i, *(aPtr + i));
    
	// ͨ����������ƫ������������
	for (i = 0; i < SIZE; i++)
		printf ("\n*(a + %d) = %d", i, *(a + i));
	
	printf ("\n");

	return 0;
}
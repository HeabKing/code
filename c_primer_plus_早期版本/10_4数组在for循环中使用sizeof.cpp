// p 247 �����嵥10.4 ����ĳ�ʼ����ʹ��sizeof��������
#include <stdio.h>
int main (void)
{
	const int days[] = {1, 2, 3, 4, 5, 6};

	for (int i = 0; i < sizeof(days) / sizeof days[0]; i++)  // �����days��ֵ���������������һ����ַ???
		printf (" %d ", days[i]);

	return 0;
}
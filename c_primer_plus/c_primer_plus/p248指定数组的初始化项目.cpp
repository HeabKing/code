// ����ĳ�ʼ��            // ���ܳɹ�����!!!!!!!!!!!!!!!!!!!!
// c primer plus �����嵥 10.5 p248
// designnate.c -- ʹ��ָ����ʼ����Ŀ    designate ָ��
#include <stdio.h>
#define MONTHS 12
int main (void)
{
	int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
	int i;
	for (i = 0; i < MONTHS; i++)
		printf ("%2d�� [%d] %d", i + 1, i, days[i]);
	
	return 0;
}
// p333 �����嵥 12.6 (��)
#include <stdio.h>

extern int count;           // ��������, �ⲿ����     extern�������, ��������������   �ڲ������ڲ�����ʹ��ʱ������������
static int total = 0;       // ��̬����, �ڲ�����
void accumulate (int k);
void accumulate (int k)
{
	static int subtotal = 0;// ��̬, ������

	if (k <= 0)
	{
		printf ("ѭ������:%d.\n", count);
		printf ("subtotal:%d, total:%d.\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total +=k;
	}
}
// ����Զ���ð�ݺ����Ա���ֵ���������÷�Χ
#include <stdio.h>
int maopao (int a, int b);
int main (void)
{
	int n1,n2;

	scanf ("%d %d", &n1, &n2);
	maopao (n1, n2);
	printf ("n1 -> %d   n2 -> %d\n", n1,n2);
	return 0;
}
int maopao (int a, int b)  // �����Զ��庯��ʱ����ʽ������������ֵ,�������Ե���ʱ�������Ĳ���û���κ�Ӱ��~~~
{
	int temp;

	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
		printf ("n1:%d.n2:%d\n", a, b);
	}
	return b;
}
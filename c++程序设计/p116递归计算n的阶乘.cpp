// ��5-8 �ݹ����һ��������n�Ľ׳�
#include <stdio.h>

long factorial (long); // factorial �׳�

int main (void)
{
	long n;

	printf ("����Ҫ��׳˵�nֵ:\n");
	scanf ("%ld", &n);
	printf("���Ϊ:%ld\n", factorial (n));
	
	return 0;
}

long factorial (long n)
{
	if (1 == n)
		return 1;
	else
		return n * factorial (n - 1);
}
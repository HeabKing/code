// ��һ�����ǲ�������
// ע��: scanf()��ɨ�赽�����ĵ�һ���ո��ʱ��ֹͣ, ������ֻ�ܶ�ȡһ������, �����Ҫ��ȡ����ʹ��gets();
#include <stdio.h>

int prime (int);

int main (void)
{
	int n;

	printf ("������һ����:\n");
	while(scanf ("%d", &n))
	{
		if(0 == prime(n))
			printf ("%d��������.\n", n);
		else
			printf ("%d������.\n", n);
	}
	return 0;
}

int prime (int n)
{
	if (1 == n)
		return 0;
	
	for (int i = 2; i * i <= n; i++)
		if (0 == n % i)
			return 0;
	
	return 1;
}
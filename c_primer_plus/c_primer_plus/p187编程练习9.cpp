// �����ϰ 7.14 (9)
// ����һ������, ��ʾС�������������������
// 2����С������, Ҳ��Ψһ��ż����
#include <stdio.h>
int main(void)
{
	int max;
	int j;

	puts("������һ����, �һ��������С�ڻ��������ֵ������.");
	scanf("%d", &max);
	for(int i = 2; i <= max; i++)
	{	
		for(j = 2; j * j <= i; j++)
		{
			if(i % j == 0)
				break;
		}
		if(j * j > i)
			printf("%d ", i);
	}

	return 0;
}
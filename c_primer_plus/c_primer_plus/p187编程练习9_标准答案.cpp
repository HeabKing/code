// �����ϰ 7.14 (9) ��׼��
#include <stdio.h>
#define YES 1
#define NO 0
int main(void)
{
	long num;
	long div;
	long lim;
	int prime;

	puts("������һ����, �һ��������С�ڻ��������ֵ������.");
	while(1 == scanf("%ld", &lim) && lim > 0)
	{
		for(num = 2; num <= lim; num++)
		{
			for(div = 2, prime = YES; (div * div) <= num; div++)
				if(num % div == 0)
					prime = NO;
			if(prime == YES)
				printf("%ld ", num);
		}
		puts("������һ����, �һ��������С�ڻ��������ֵ������.");
	}

	return 0;
}
// ��N��Ӳ��, ʵ��M��
#include <stdio.h>
#include <stdlib.h>

int heads()
{
	return rand() < RAND_MAX/2;
}

int main(void)
{
	int i, j, cnt;
	int N, M;
	
	printf("��Ӳ�Ҵ���: ");
	scanf("%d", &N);
	printf("ʵ�����: ");
	scanf("%d", &M);
	
		// Ϊ��Ӳ�ҵĴ��������ڴ�ռ�  ID: 0 - N�ֱ��ʾ��N��Ӳ��, ���泯��ID��, ��Ӧ�����ֵ��ID����ִ��M������¶�Ӧ�Ĵ���
	int *f = (int *)malloc((N+1) * sizeof(int));

		// ����ʼֵ��ֵΪ0
	for (j = 0; j <= N; j++)
		f[j] = 0;

		// ��N��, ִ��M��
	for (i = 0; i < M; i++)	// M��
	{
			// ͳ�����泯�ϵĴ���
		for (cnt = 0, j = 0; j <= N; j++)	// N��
			if (heads())	// ������泯��
				cnt++;

			// �����泯�ϵĴ������Ӧ������ID��һ
		f[cnt]++;
	}

		// ���
	for (j = 0; j <= N; j++)
	{
		printf("%2d", j);
		for (i = 0; i < f[j]; i += 10)
			printf("*");
		printf("\n");
	}

	return 0;
}
					// �ϲ� - �����㷨 ֮ ���ٺϲ�(��������)�ļ�Ȩ�汾

// ʵ��˼·�Ǵ�����С��(�����ĸ���Ϊ�����ĸ�)

#include <cstdio>
#define  N	10000

int main(void)
{
	int i, j, p, q, id[N];
	int sz[N];  // ���ڴ洢ÿ�����ṹ��Ԫ�ص�����;
				// ÿ�����ṹ�ĸ�Ԫ�ض�Ӧ������ƫ����(���䱣���ֵ)��Ӧ��szͬλ�ñ����˴����ṹ��Ԫ������;
	
	for (i = 0; i < N; i++)
	{
		id[i] = i;
		sz[i] = 1;
	}

	while (scanf("%d %d\n", &p, &q) == 2)
	{

			// ����

		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);

				// ȥ����ͨ��
		if (i == j)
			continue;

			// �ϲ�

				// �Ƚ����Ĵ�С, ��С���ĸ�����Ϊ������;
		if (sz[i] < sz[j])
		{
			id[i] = j;
			sz[j] += sz[i];
		} 
		else
		{
			id[j] = i; 
			sz[i] += sz[j];
		}

			// ���û��ͨ��

		printf("\t\t%d %d\n", p, q);
	}

	return 0;
}
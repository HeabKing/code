// ���ٲ��� ���ٺϲ�
#include <stdio.h>

const int N = 10;

int main(void)
{
	int id[N];

	for (int i = 0; i < N; i++)
		id[i] = i;

	int p, q;

	while (scanf("%d %d", &p, &q) == 2)
	{
		int i, j, num = 0;
		for (i = p; i != id[i]; i = id[i])num++;
		for (j = q; j != id[j]; j = id[j])num++;
		if (j == i)
			continue;
		id[i] = q;

		printf("\t\t%d %d �����������: %d\n\t\t", p, q, num);
		for (i = 0; i < N; i++)
			printf("%d ", id[i]);
		printf("\n");
	}

	return 0;
}
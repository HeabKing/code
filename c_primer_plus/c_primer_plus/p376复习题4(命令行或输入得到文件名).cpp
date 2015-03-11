// ��ϰ�� 13.10 ��������double��ƽ��ֵ
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE * fp;
	int count = 0;
	double dou;
	double tot = 0, avg = 0;

	if (argc == 2)
	{
		if (NULL == (fp = fopen(argv[1], "r")))
		{
			fprintf(stderr, "�޷���%s�ļ�\n", argv[1]);
			getchar();
			exit(EXIT_FAILURE);
		}
		while (fscanf(fp, "%lf", &dou) == 1)
		{
			tot += dou;
			count++;
		}
	}
	else if (argc == 1)
		while (scanf("%lf", &dou) == 1)
		{
			tot += dou;
			count++;
		}
	else
	{
		fprintf(stderr, "�����в�������ȷ.\n");
		getchar();
		exit(EXIT_FAILURE);
	}

	avg = tot / count;
	printf("һ��������%d��double����, �ܺ�Ϊ%lf, ƽ����Ϊ%lf\n", count, tot, avg);
	getchar();

	return 0;
}
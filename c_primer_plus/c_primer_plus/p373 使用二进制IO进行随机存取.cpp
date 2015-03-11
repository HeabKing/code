#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(void)
{
	double numbers[ARSIZE];
	double value;
	const char * file = "p373numbers.dat";
	int i;
	long pos;
	FILE * infile;

	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	
	if (NULL == (infile = fopen(file, "wb")))
	{
		fprintf(stderr, "���ܴ�%s�ļ�.\n", file);
		exit(EXIT_FAILURE);
	}

	// �������е������Զ�������ʽд���ļ�
	fwrite(numbers, sizeof(double), ARSIZE, infile);
	fclose(infile);

	if (NULL == (infile = fopen(file, "rb")))
	{
		fprintf(stderr, "���ܴ��ļ�%s\n", file);
		exit(EXIT_FAILURE);
	}

	// ��ʼ���п�ѡ��ȡ
	printf("����һ�� 0 - %d ������.\n", ARSIZE - 1);
	while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double);  // ����ƫ����
		fseek(infile, pos, SEEK_SET);  // ��λ����ѡλ��
		fread(&value, sizeof(double), 1, infile);
		printf("����value��ֵΪ%f.\n", value);
		puts("������һ������:");
	}
	fclose(infile);

	return 0;
}
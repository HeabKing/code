// p373 �����嵥 13.7
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main (void)
{
	double numbers[ARSIZE];
	double value;
	const char * file = "p373numbers.dat";
	int i;
	long pos;
	FILE * iofile;

	// ����һ��double���͵���ֵ
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	// ���Դ��ļ���д��
	if (NULL == (iofile = fopen (file, "wb")))
	{
		fprintf (stderr, "���ܴ�%s�ļ�.\n", file);
		exit (1);
	}
	// �������е������Զ�������ʽд���ļ�
	fwrite (numbers, sizeof (double), ARSIZE, iofile);
	fclose (iofile);
	// ���Դ��ļ�����ȡ
	if (NULL == (iofile = fopen (file, "rb")))
	{
		fprintf (stderr, "���ܴ�%s�ļ�.\n", file);
		exit (1);
	}
	// ���ļ��ж�ȡ��ѡ��Ŀ
	printf ("����һ�� 0 - %d ������.\n", ARSIZE - 1);
	scanf ("%d", &i);
	while (i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof (double);  // ����ƫ����
		fseek (iofile, pos, SEEK_SET);    // ���ļ��ж�λ������
		fread (&value, sizeof (double), 1, iofile);
		printf ("����value��ֵΪ%f.\n", value);
		puts ("������һ������:");
		scanf ("%d", &i);
	}
	fclose (iofile);
	puts ("ok!");

	return 0;
}
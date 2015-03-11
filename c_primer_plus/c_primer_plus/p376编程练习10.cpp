// �����ϰ 13.11 �û�����һ���ļ�λ��, ��ӡ����λ�õ���һ�����з�
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * fp;
	char filename[81];
	long pos, last;

	puts("File name: ");
	gets(filename);
	if (NULL == (fp = fopen(filename, "rb")))
	{
		fprintf(stderr, "Can't open %s.\n", filename);
		exit(EXIT_FAILURE);
	}

	puts("����һ���ļ�λ��(�������˳�):");
	while (scanf("%ld", &pos) == 1)
	{
		fseek(fp, 0L, SEEK_END);
		last = ftell(fp);
		if (pos >= last)
		{	
			fprintf( stderr, "��������ִ���%d, ��������:\n", last);
			continue;
		}
		fseek(fp, pos, SEEK_SET);
		fgets(filename, 81, fp);
		fputs(filename, stdout);
		puts("����һ���ļ�λ��(�������˳�):");
	}

	puts("Done!");

	return 0;
}
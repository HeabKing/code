// p371 �����嵥 13.6 �Ѷ���ļ�������׷�ӵ�һ���ļ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024         // ��������С     buffer ����
#define SLEN 81              // �ļ����ƴ�С���޶�

void append (FILE * source, FILE * dest);

int main (void)
{
	FILE * fa, * fs;         // faָ��Ŀ���ļ�, fsָ��Դ�ļ�
	int files = 0;           // ׷���ļ��ĸ���
	char file_app [SLEN];    // Ŀ���ļ�������
	char file_src [SLEN];    // Դ�ļ�������

	// ��Ŀ���ļ�
	puts ("����Ŀ���ļ�������:");
	gets (file_app);
	if (NULL == (fa = fopen (file_app, "a")))  // ׷��д��ģʽ
	{
		fprintf (stderr, "���ܴ�Ŀ���ļ�%s!\n", file_app);
		exit (2);
	}

	// ����Ŀ���ļ��Ļ�����
	if (setvbuf (fa, NULL, _IOFBF, BUFSIZE) != 0)            // �ɹ�ִ�з���0 �����0
	{
		fputs ("���ܴ���������!\n", stderr);
		exit (3);
	}

	// ��Դ�ļ�
	puts ("�����һ��Դ�ļ�������(���н���).");
	while (gets (file_src) && file_src[0] != '\0')
	{
		if (strcmp (file_src, file_app) == 0)               // �Ƚ�Դ�ļ���Ŀ���ļ������Ƿ���ͬ
		{	
			fputs ("���ܶ��ļ��������׷��!����������\n", stderr);
			continue;
		}
		else if (NULL == (fs = fopen (file_src, "r")))
			fprintf (stderr, "���ܴ�%s�ļ�!\n", file_src);
		else
		{
			if (setvbuf (fs, NULL, _IOFBF, BUFSIZE) != 0)  // �ɹ�ִ�з���0 �����0
			{
				fputs ("���ܴ���������!!", stderr);
				continue;
			}
			append (fs, fa);
			if (ferror (fs) != 0)
				fprintf (stderr, "��ȡ%sԴ�ļ�ʧ��!\n", file_src);
			if (ferror (fa) != 0)
				fprintf (stderr, "д��%sĿ���ļ�ʧ��!\n", file_app);
			fclose (fs);
			files++;
			printf ("Դ�ļ�%s�Ѿ�׷�ӵ���Ŀ���ļ�!\n", file_src);
			puts ("��������һ��Դ�ļ�(�����˳�).");
		}
	}
	printf ("Done. %d files appended!\n", files);
	fclose (fa);

	return 0;
}

void append (FILE * source, FILE * dest)             // destination Ŀ��
{
	size_t bytes;
	static char temp[BUFSIZE];                       // ����һ��

	while ((bytes = fread (temp, sizeof (char), BUFSIZE, source)) > 0)
		fwrite (temp, sizeof (char), bytes, dest);   // ������������д���ļ�
}
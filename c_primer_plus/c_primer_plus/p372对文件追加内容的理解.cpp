// �Լ�д�ļ���p371��������
#include <stdio.h>
#include <stdlib.h>          // Ϊexit()�ṩ����ԭ��
#include <string.h>          // Ϊstrcmp()�ṩ����ԭ��
#define FNAME 81

void append (FILE * source, FILE * dest);

int main (void)
{
	FILE * fa, * fs;
	char file_app[FNAME], file_src[FNAME];

	// Ŀ���ļ�
	puts ("������Ŀ���ļ���:");
	gets (file_app);
	if (NULL == (fa = fopen (file_app, "a")))
	{
		printf ("���ܴ�Ŀ���ļ�%s!\n", file_app);
		exit (EXIT_FAILURE);
	}
	else
		printf ("�ɹ���%s!\n", file_app);

	// Դ�ļ�
	puts ("������Դ�ļ�(�����˳�):");
	while (gets (file_src) && file_src[0] != '\0')  // gets() ��ȡ'\n'�Ժ��滻��'\0' ���Բ�д��'\n'
	{
		if (strcmp (file_app, file_src) == 0)
		{	
			puts ("���ܶ�Ŀ���ļ��Լ�����׷�Ӳ���!����������!");
			continue;
		}
		else if (NULL == (fs = fopen (file_src, "r")))
		{
			puts ("���ܴ򿪴�Դ�ļ�!����������");
			continue;
		}
		else
		{
			append (fa, fs);
			fclose (fs);
			puts ("�Ѿ��ɹ���Ŀ���ļ�������׷��!\n��������һ��Դ�ļ�(�����˳�):");
		}
	}

	// ��β
	fclose (fa);
	puts ("ok!");

	return 0;
}

void append (FILE * dest, FILE * source)
{
	char str[4];

	while (fgets (str, 4, source) != NULL)
	{
		fputs (str, dest);
	}
}
// p376 �����ϰ 13.11 (8)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_file (char ch, FILE * file);
int find_std (char ch);

int main (int argc, char * argv[])
{
	FILE * file;
	char ch;
	int i;

	// δ�����ļ���
	if (argc < 3)
	{   // �ַ�
		puts ("������Ҫ���ҵ��ַ�:");
		scanf ("%c", &ch);
		printf ("std ->>%c->> %d.\n", ch, find_std (ch));
	}
	// �������ļ���
	else
		for (i = 2; i < argc; i++)
		{
			if (NULL == (file = fopen (argv[i], "r")))
			{
				printf ("���ܴ��ļ�%s!\n", argv[i]);
				exit (EXIT_FAILURE);
			}
			printf ("%s ->>%c->> %d.\n", argv[i], argv[1][0], find_file (argv[1][0], file));
			fclose (file);
		}
	system ("pause");
	puts ("ok!");

	return 0;
}

int find_std (char ch)
{
	int count = 0;
	char t_ch;

	puts ("������Ҫ���в��ҵ��ı�('|'����):");
	while ((t_ch = getchar()) != '|')
	{	
		if (t_ch == ch)
			count++;
	}
	return count;
}

int find_file (char ch, FILE * file)
{
	int count = 0;
	char t_ch;

	while ((t_ch = getc (file)) != EOF)
	{	
		if(t_ch == ch)
			count++;
	}

	return count;
}
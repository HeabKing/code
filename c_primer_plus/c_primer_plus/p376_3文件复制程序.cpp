// p376 �����ϰ 13.11 (3) �ļ����� ת���ɴ�д
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // Ϊtoupper()�ṩԭ��
#define NAMESIZE 81
#define ARRSIZE 1024

void copy (FILE * dest, FILE * source);

int main (void)
{
	FILE * dest, * source;
	char file_dest[NAMESIZE], file_source[NAMESIZE];
	int i;

	// Ŀ���ļ�
	puts ("������Ŀ���ļ���:");
	gets (file_dest);
	if (NULL == (dest = fopen (file_dest, "wb")))
	{
		printf ("���ܴ�Ŀ���ļ�%s.\n", file_dest);
		exit (EXIT_FAILURE);
	}
	else
		puts ("�ɹ���Ŀ���ļ�!");
	
	// Դ�ļ�
	puts ("������Դ�ļ���:");
	gets (file_source);
	if (NULL == (source = fopen (file_source, "rb")))
	{
		printf ("���ܴ�Դ�ļ��ļ�%s.\n", file_source);
		exit (EXIT_FAILURE);
	}
	else
		puts ("�ɹ���Դ�ļ�!");

	// �ļ����� ת���ɴ�д
	copy (dest, source);
	
	// ��β
	fclose (dest);
	fclose (source);
	puts ("���Ƴɹ�!");

	return 0;
}

void copy (FILE * dest, FILE * source)
{
	char buf[ARRSIZE];
	char temp[ARRSIZE];
	int i;

	while (fgets (buf, ARRSIZE, source) != NULL)
	{
		for (i = 0; i < (int) sizeof (buf) / (int) sizeof (char); i++)
			buf[i] = toupper (buf[i]);
		fputs (buf, dest);
	}
}
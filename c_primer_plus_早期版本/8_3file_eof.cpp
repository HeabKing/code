// c primer plus �����嵥 8.3 p195
// file_eof.c -- ��һ���ļ�����ʾ������
#include <stdio.h>
#include <stdlib.h>                          // Ϊ��ʹ��exit()
int main (void)
{
	int ch;                                  // Ϊ��ʹ��EOF����Ϊint
	FILE * fp;
	char fname[50];                          // ���ڴ���ļ���

	printf ("Enter the name of the file:\n");
	scanf ("%s", fname);                     // �����fnameû�м�&����
	fp = fopen (fname, "r");                 // ���ļ��Թ���ȡ
	if (fp == NULL)                          // ���Դ��ļ�ʧ��
	{
		printf ("Failed to open the file. Bye!\n");
		exit (1);                            // ��ֹ����
	}
	// getc (fp) �Ӵ򿪵��ļ��л�ȡһ���ַ�
	while ((ch = getc (fp)) != EOF)
		putchar (ch);
	printf ("\n");
	fclose (fp);                             //�ر��ļ�
	return 0;
}
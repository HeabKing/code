// p361 �����嵥 13.3
#include <stdio.h>
#include <stdlib.h>
#define MAX 40
int main (void)
{
	FILE * fp;
	char words[MAX];

	if (NULL == (fp = fopen ("words.txt", "a+")))      // a+ �������һ�����Զ���д���ļ�, ����ļ��Ѿ�����, ��д������׷�ӵ��ļ�β��
	{
		fprintf (stdout, "���ܴ�\"words.txt\"�ļ�!\n");
		exit (1);
	}
	puts ("����Ҫ����д�������, ͨ���ڿ��а�enter����.");
	while (gets (words) != NULL && words[0] != '\0')
		fprintf (fp, "%s", words);
	puts ("File contents:");
	rewind (fp);                                       // �ص��ļ��Ŀ�ʼ��
	while (fscanf (fp, "%s", words) == 1)
		puts (words);
	if (fclose(fp) != 0)
		fprintf (stderr, "�޷��ر��ļ�!\n");

	return 0;
}
// p363 �����嵥 13.4 -- �ļ�����
#include <stdio.h>
#define MAXLINE 4
int main (void)
{
	char line[MAXLINE];
	FILE * fp;
	fp = fopen ("words.txt", "r");
	while (fgets (line, MAXLINE, fp) != NULL)   // MAXLINE��ʾ�����ַ�������󳤶�
	{
		puts("...");
		fputs (line, stdout);
		printf ("-%c-%c-%c-", line[0], line[1], line[2]);  // ��������һ���س���������������, ��ʵ�ǵ���һ��Ϊ�س���ʱ���Զ���ջ���, ����line[1]Ϊ'\0'
		putchar ('\n');
		puts("...");
	}
	return 0;
}
// fgets() ��ȡ�����������ĵ�һ�������ַ��ĺ���, ���߶�ȡ���ַ�����󳤶���һ�����ַ�, ���߶����ļ���β.
// Ȼ��fgets()��ĩβ���һ�����ַ��Թ���һ���ַ���.
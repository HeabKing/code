// p363 �����嵥 13.4 -- ��������
#include <stdio.h>
#define MAXLINE 20
int main (void)
{
	char line[MAXLINE];
	
	while (fgets (line, MAXLINE, stdin) != NULL   // MAXLINE��ʾ�����ַ�������󳤶�
			&& line[0] != '\n')
		fputs (line, stdout);
	return 0;
}
// fgets() ��ȡ�����������ĵ�һ�������ַ��ĺ���, ���߶�ȡ���ַ�����󳤶���һ�����ַ�, ���߶����ļ���β.
// Ȼ��fgets()��ĩβ���һ�����ַ��Թ���һ���ַ���.
// �����ϰ 11.13 (6)
// һ����strncpy()һ���ĺ���
// strncpy(s1, s2, n)��s2����n���ַ���s1, ���ڱ�Ҫʱ�ض�s2��Ϊ��������Ŀ��ַ�, ���s2�ĳ��ȵ��ڴ���n, Ŀ���ַ�����û�б�־�����Ŀ��ַ�, ��������s1;
#include <stdio.h>
#include <string.h>
#define SIZE 80
char * strncpy_make(char *, char *, int);
int main(void)
{
	char s1[SIZE];
	char s2[SIZE];
	
	gets(s1);
	gets(s2);
	strncpy_make(s1, s2, 10);
	puts(s1);

	return 0;
}

char * strncpy_make(char * s1, char * s2, int n)
{
	int i;
	for (i = 0; i < n; i++)
		s1[i] = s2[i];
	if (i < n)
		s1[i] = '\0';
	return s1;
}
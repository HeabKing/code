//����ж������ַ�ʱ��ĸ���Ƿ���ĸ
//c primer plus �����嵥 7.3
//cypher1.c -- �ı�����,ֻ������ĸ�ַ�
#include <stdio.h>
#include <ctype.h>
int main (void)
{
	char ch;

	while((ch = getchar()) != '\n')
	{
		if (isalpha(ch))
			putchar (ch + 1);
		else
			putchar (ch);
	}
	putchar (ch);
	return 0;
}
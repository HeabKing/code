//getchar()��putchar()
//c primer plus �����嵥 7.2
//cypher.c -- �ı�����,ֻ�������еĿո�
#include <stdio.h>
#define SPACE ' '
int main (void)
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (ch == SPACE)
			putchar (ch);
		else
			putchar(ch + 1);
	}
	putchar (ch);
	return 0;
}
// EOF��ֹ��������
// C primer plus �����嵥 8.2 p191
// echo_eof.c -- �ظ�����,ֱ���ļ���β
#include <stdio.h>
int main (void)
{
	int ch;     // �ļ��Ľ�βΪEOF ��EOF��ֵ�п���Ϊ-1 ���char(0-255)�ǲ����ܵ� // ���Ƕ���ΪcharҲ�� ���ǲ�����õ���ʽ

	printf ("�ڱ�pc��,ֻ����ÿ�еĿ�ʼ����Ctrl+z�ᱻ��Ϊ���ļ���β.\n");
	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}
//c primer plus �����嵥 4.10 ʹ�����η��ͱ�־ʾ��(4)
//strings.c -- �ַ����ĸ�ʽ��
#include <stdio.h>
#define BLURB "Authentic imitation!"
int main ()
{
	printf ("/%2s/\n", BLURB);
	printf ("/%24s/\n", BLURB);
	printf ("/%24.5s/\n", BLURB);
	printf ("/%-24.5s/\n", BLURB);
	return 0;
}
//����û���������˵�˫���ź;���⹫���ٸ��ַ�
//c primer plus �����嵥 7.6
//chcount.c -- ʹ���߼������
#include <stdio.h>
#define PERIOD '.'
int main (void)
{
	char ch;
	int charcount = 0;

	printf ("�����뼸���ַ�:\n");
	while ((ch = getchar()) != '.')
	{
		if (ch != '"' && ch != '\'')
			charcount++;	
	}
	printf ("There are %d non-quote characters.\n", charcount);
	return 0;
}
// �����ϰ 7.12 (1)
// ͳ���ַ�������Ϣ
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int n_chars = 0;
	int n_space = 0;
	int n_lines = 1;
	char ch;

	while('#' != (ch = getchar()))
	{
		if(isspace(ch))
			n_space++;
		else
			n_chars++;
		if(ch == '\n')
			n_lines++;
	}
	printf("��%d���ǿ��ַ�, %d��, %d���հ��ַ�\n",
		n_chars, n_lines, n_space);

	return 0;
}
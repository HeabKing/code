// �����ϰ 11.13 (8)
// ��һ���ַ�������ĺ���
#include <stdio.h>

char * fanxu(char *);

int main(void)
{
	char str1[80] = "heshixiong";

	fanxu(str1);
	puts(str1);

	return 0;
}

char * fanxu(char * str)
{
	int i = 0, j;
	char temp;
	while (str[i])
		i++;
	i -= 1;
	for (j = 0; j < i; j++, i--)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
	}
	return str;
}
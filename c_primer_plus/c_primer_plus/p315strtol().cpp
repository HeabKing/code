// �����嵥 11.29
// long strtol(const char * nptr, char ** endptr, int bse); nptr��ָ��ϣ��ת�����ַ�����ָ�� endptr��ָ���־�������ֵĽ����ַ���ָ��ĵ�ַ, base�����ֵĻ���(���36����ʹ��һֱ��'z'��Ϊ����)
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char number[30];
	char * end;
	long value;

	puts("Enter a number (empty line to quit):\n");
	while (gets(number) && number[0] != '\0')
	{
		value = strtol(number, &end, 10);
		printf("value: %ld, stopped at %s (%d)\n", value, end, *end); // ����������"12\0"��ôend�������'\0'�ĵ�ַ, end(%s)����Ļ����ַ���Ϊ��, ʲô�������, *end(%d)����Ļ�ֻ�����0
		value = strtol(number, &end, 16);
		printf("value: %ld, stopped at %s (%d)\n", value, end, *end);
		value = strtol(number, &end, 8);
		printf("value: %ld, stopped at %s (%d)\n", value, end, *end);
	}

	return 0;
}
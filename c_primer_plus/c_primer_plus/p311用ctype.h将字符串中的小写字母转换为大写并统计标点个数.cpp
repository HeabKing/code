// p311 �����嵥 11.26
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMT 80

void ToUpper (char *);           // ��Сд��ĸת��Ϊ��д
int punctcount (const char *);   // ͳ���ַ����б����ŵĸ���

int main (void)
{
	char line[LIMT];

	puts ("����һ���ַ���,�Ұ����Сд���д������������ŵĸ���:");
	gets (line);
	ToUpper (line);
	puts (line);
	printf ("��%d��������!\n", punctcount(line));

	return 0;
}

void ToUpper (char * str)
{
	while (*str)
	{
		*str = toupper (*str);     // ǰ���*str = �������!!!!!!!!!!!!
		str++;
	}

	return;
}

int punctcount (const char * str)
{
	int count = 0;
	while (*str)
	{
		if (ispunct (*str))
			count++;
		*str++;
	}
		
	return count;
}
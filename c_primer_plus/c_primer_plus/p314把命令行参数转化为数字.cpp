// p314 �����嵥 11.28
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv)
{
	int i, times;

	if (argc < 2 || (times = atoi (argv[2])) < 1)
		puts ("�������!");
	else
		for (i = 1; i <= times; i++)
			puts (argv[1]);
	printf("%d", atoi("h")); // . atoi�Ĳ�����һ��ָ��, atoi���ת���Ĳ��������ַ�ָ��ͻ᷵��0
	scanf ("%d", &i);

	return 0;
}
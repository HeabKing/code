// �����ӡһ���ַ���
#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(void)
{
	char ar[SIZE];

	puts("����һ���ַ����Ҹ��㷴���ӡ����:");
	gets(ar);
	for(int i = strlen(ar) - 1; i >= 0; i--)
	{
		putchar(ar[i]);
	}
	putchar('\n');

	return 0;
}
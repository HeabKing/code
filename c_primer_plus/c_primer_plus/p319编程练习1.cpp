// �����ϰ 11.13 (1)
#include <stdio.h>
#define SIZE 11

char * read_n(char *, int);

int main()
{
	char ar[SIZE];
	printf("����һ���ַ�, �ҽ����ǰ%d���������:\n", SIZE - 1);
	if (NULL == read_n(ar, SIZE - 1))
		puts("Input failed!");
	else
		puts(ar);

	return 0;
}
char * read_n(char * ar, int n)
{
	int i = 0;
	char ch;
	
	while ((ch = getchar()) != EOF)
		if (i < n)
			ar[i++] = ch;
	if (ch == EOF && i < n)
		return NULL;          // ��˼���ڶ���n���ַ�֮ǰʹ��EOF�ᵼ�·���ֵΪNULL���Ҳ���Ϊ����β������'\0'
	else
		ar[i] = '\0';
	
	return ar;
}
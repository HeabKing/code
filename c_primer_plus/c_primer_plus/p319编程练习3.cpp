// �����ϰ 11.13 (3)
// ���һ��i����, ��ȡһ���е�һ������, �����������ʶ���
#include <stdio.h>
#include <ctype.h>
void gett(char *, int size);    // �Լ���һ��д��
char * gettt(char *, int);

int main()
{
	char ar[10];
	gett(ar, 10);
	puts(ar);

	char arr[11];
	while (NULL != gettt(arr, 11 - 1))
		puts(arr);

	return 0;
}
void gett(char ar[], int size)
{
	char ch;
	int i = 0;
	int flag = 0;
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		if (!isspace(ch) && flag != 3 && i < size - 1)
		{
			ar[i++] = ch;
			flag = 1;
		}
		else if (isspace(ch) && flag == 1)
			flag = 3;
	}
	ar[i] = '\0';
}

char * gettt(char * ar, int size)
{
	char ch;
	int i = 0;
	while ((ch = getchar()) != EOF && !isspace(ch) && i < size)
			ar[i++] = ch;
	ar[i] = '\0';

	if (ch == EOF)
		return NULL;

	while (getchar() != '\n')
		continue;

	return ar;
}
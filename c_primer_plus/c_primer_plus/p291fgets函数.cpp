// p291 �����嵥 11.6
// ע�⵽gets();�и��׶�, �����ܼ������Ƿ񳬹�����("���"����������). fgets();�����������
// ����ڶ���������n�������Զ���n-1���ַ����߶���һ�����з�Ϊֹ, ���ᴢ�滻�з���������gets()������������
// ����Ҫ������������ָ������һ���ļ�
// ##### ������������, ������fgets()��gets()һ�� #############
#include <stdio.h>
#define MAX 81

int main (void)
{
	char name[MAX];
	char name1[4];
	char * namePtr;

	printf ("�������������:");			// fgets ��ѻ��з�Ҳ������ȥ
	namePtr = fgets (name, MAX, stdin);   // Ϊ�ַ�������ĵ�ַname, ����MAX, ����ķ�ʽstdin(standard input ��������)
	printf ("%s? Hello, %s\n", name, namePtr);
	printf("�����ֻ�ܱ������������ַ�:");
	fgets(name1, 4, stdin);
	printf("%s\n", name1);

	printf("һ��ѭ���������ַ�(EOF���Խ���):\n");
	while (fgets(name1, 4, stdin) != NULL)
	{
		printf("%s\n", name1);
		printf("һ��ѭ���������ַ�(EOF���Խ���):\n");
	}
	return 0;
}
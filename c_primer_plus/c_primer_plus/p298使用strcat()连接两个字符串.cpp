// p298 �����嵥 11.14
// strcat(a, b); ��b�������滻����һ������'\0'�ĵط�
// string concatenation ����һ��ȱ�� ����������һ��char�����Ƿ��ܹ����ɵڶ����ַ���
#include <stdio.h>
#include <string.h>
#define SIZE 80

int main (void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes!";
	puts("Whats your favorite flower?");
	gets(flower);                     // gets()�����ȡ'\n'
	strcat(flower, addon);
	puts (flower);
	puts (addon);					  // �ڶ����ַ�������

// ��һ��char����װ���µڶ��������
	char ar1[4];
	char ar2[] = "daxionggege";
	puts(ar2);
	gets(ar1);	// ���������ַ��ͻ�����ڴ�Խ��
	strcat(ar1, ar2);
	puts(ar1);    // ��Ȼ���Խ��
	puts(ar2);

	return 0;
}
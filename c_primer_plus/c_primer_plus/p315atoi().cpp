// �Լ��ܽ�
#include <stdio.h>
#include <stdlib.h> // Ϊatoi()�ṩԭ��
int main(void)
{
	char * str1 = "12";
	char * str2 = "34heshixiong";
	char * str3 = "he56shixiong";
	char * str4 = "he7shixio8ng";
	char * str5 = "heshixiong";

	printf("%d\n", atoi(str1) * 2); // . int atoi(const char *);
	printf("%d\n", atoi(str2) * 2); // ���������"34heshixiong"���ص���34
	printf("%d\n", atoi(str3) * 2); // ����ֵΪ0, ���Ǳ�׼c�涨������Ϊ��δ�����
	printf("%d\n", atoi(str4) * 2); // ����ֵΪ0, ���Ǳ�׼c�涨������Ϊ��δ�����
	printf("%d\n", atoi(str5) * 2); // ����ֵΪ0, ���Ǳ�׼c�涨������Ϊ��δ�����

	return 0;
}
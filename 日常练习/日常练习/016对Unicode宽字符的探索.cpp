#include <string.h>
#include <stdio.h>

int main(void)
{
	printf("char - strlen: %d\n", strlen("123456"));
	printf("wchar - strlen: %d\n", strlen((char *)(L"123456")));  // ��Ϊ����ɵڶ����ַ���00������'\0' ������ʾΪһ���ַ�
	printf("wchar - wcslen: %d\n", wcslen(L"123456"));  // �ɹ�ִ���� �����L�������ȥ����

	return 0;
}
// �����嵥 16.4 #��##
#include <stdio.h>
#define XNAME(n) bianliang ## n  // ���ڱ�������ճ�ϼ� ��д��һ��������
#define PRINT_XN(n) printf("bianliang" #n " = %d\n", bianliang ## n);  // #����һ��Ԥ���������, ���԰����Է���ת�����ַ��� ##���������Է�����ϳ�һ�����Է���
								// #n �Ѳ���ת������Ӧ���ַ���
int main(void)
{
	int XNAME(1) = 14;  // change to bianlinag1 = 14
	int XNAME(2) = 20;  // change to bianliang2 = 20
	PRINT_XN(1);  // change to printf("bianliang1 = %d\n", bianliang1);
	PRINT_XN(2);  // change to printf("bianliang2 = %d\n", bianliang2);
		// #2ת������"2" printf("bianliang""2"" = %d\n", bianliang2);
	int temp = bianliang1 + bianliang2;
	printf("%d\n", temp);

	return 0;
}
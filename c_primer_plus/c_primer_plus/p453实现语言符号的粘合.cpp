// �����嵥 16.4 ## ʵ�����Է��ŵ�ճ��
#include <stdio.h>
#define XNAME(n) x ## n
#define YNAME x3
#define PRINT_XN(n) printf ("x" #n " = %d\n", x ## n);

int main (void)
{
	int XNAME(1) = 14; // ��Ϊint x1 = 14;
	int XNAME(2) = 20; // ��Ϊint x2 = 20;
	int YNAME = 10;
	PRINT_XN(1);       // ��Ϊprintf ("x1 = % d \n", x1);
	PRINT_XN(2);       // ��Ϊprintf ("x2 = % d \n", x2);
	printf("%d", x3);
	return 0;
}
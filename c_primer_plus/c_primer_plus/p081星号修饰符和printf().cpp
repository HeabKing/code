// �����嵥 4.16
// *���η���printf()����
// ʹ����%*d����ô������Ӧ��һ��ָ��*��ֵ, һ��ָ��d��ֵ
#include <stdio.h>
int main(void)
{
	printf ("--%*d---\n", 5, 3);
	printf ("--%*.*f---", 5, 2, 3.2);

	return 0;
}
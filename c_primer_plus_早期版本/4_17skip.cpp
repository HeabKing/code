//printf()��scanf()��*���η� 4.4.6 (2)
//c primer plus �����嵥 4.17
//skip.c -- ���������ͷ��������
#include <stdio.h>
int main ()
{
	int n;

	printf ("Please enter three integers: \n");
	scanf ("%*d %*d %d",&n);
	printf ("The last integer was %d\n",n);
	return 0;
}
//*���η�ʹscanf()����������Ӧ��������Ŀ
//���в����ĺ���
//c primer plus �����嵥5.15
//pound.c --  ����һ�����в����ĺ���
#include <stdio.h>
void pound (int n);  //ANS����ԭ��
int main (void)
{
	int times = 5;
	char ch = '!';
	float f = 6.0;
	pound (times);
	pound (ch);
	pound ((int)f);
	return 0;
}
void pound (int n)
{
	while (n-- > 0)
		printf ("#");
	printf ("\n");
}
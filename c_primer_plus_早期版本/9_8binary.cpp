// �ݹ�ͷ�������  �ڷ���������,�ݹ��ѭ����
// c primer plus �����嵥 9.8 p228 
// binary.c -- �Զ�������ʽ�������
#include <stdio.h>
void to_binary (unsigned long);      // binary (������)

int main (void)
{
	unsigned long number;
	
	printf ("Enter an integer (q to qiut): \n");
	while (scanf ("%ul", &number) == 1)
	{
		printf ("Binary equivalent: ");
		to_binary (number);
		putchar ('\n');
		printf ("Enter an integer (q to qiut): \n");
	}
	printf ("Bye!\n");

	return 0;
}

void to_binary (unsigned long n)    // �ݹ麯������
{
	int r;

	r = n % 2;
	if (n >= 2)
		to_binary (n / 2);          // �������� 5 / 2���2.5�Զ�ת��Ϊ2
	putchar ('0' + r);              // �ַ�'1'�ı����ַ�'0'�Ĵ�1;����putchar()���1����д��putchar('0' + 1)
//  putchar (r ? '1' : '0');  Ҳ�ǿ��Ե�
	return;                         // returnΪ���ǲ��Ǿ��Ǹ���֮�䲻����return?������main?
}
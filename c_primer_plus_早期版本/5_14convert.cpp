//���͵��Զ�ת��
//c primer plus �����嵥 5.14
//convert.c -- �Զ�����ת��
#include <stdio.h>
int main ()
{
	char ch;
	int i;
	float f1;

	f1 = ch = i = 'C';  //C����Ϊ1�ֽڵ�ASCIIֵ������ch��;Cת��������67,��4���ֽڴ�����i��;

	printf ("ch = %c, i = %d, f1 = %2.2f\n", ch, i, f1);
	ch = ch + 1;  //��Ϊ�����Ĳ�������ʱ,char��short�ᱻת����int
	i = f1 + 2 * ch;  //��ֵʱ'='�ұߵ���������ͳһ������ߵ�
	f1 = 2.0 * ch + i;
	printf ("ch = %c, i = %d, f1 = %2.2f\n", ch, i, f1);
	ch = 5212205.17;
	printf ("Now ch = %c\n",ch);  //chΪһ���ܴ���� �ڽ�����ȡ��λ�� ch���ձ����'-'��ascii��
	return 0;
}
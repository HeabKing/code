// �����嵥 3.4
#include <stdio.h>
int main (void)
{
	unsigned int unint = 3000000000; // int �ķ�Χ���ɴﵽ '��'
	unsigned int un = 123456789;
	short shint = 200;
	unsigned short end = 100;
	long big = 65537;
	long long verybig = 12345678908642;
	printf ("unint = %u not is %d\n", unint, unint);
	printf ("un = %u not is %ud\n\n", un, un);
	printf ("shint = %hd and %d\n", shint, shint); // ֮���Կ�����%d��ʾshort��������Ϊshort�����ڽ��в������ݵ�ʱ���Զ��任Ϊint����, ��Ϊint���ͱ���Ϊ�Ǽ�����������������Ч������
	printf ("end = %hu and %u\n\n", end, end);
	printf ("big = %ld and not %hd\n", big, big);  // ��%hd˵����ֻ����ʾ���ĺ�16λ
	printf ("verybig = %lld and not %ld", verybig, verybig);
	return 0;
}
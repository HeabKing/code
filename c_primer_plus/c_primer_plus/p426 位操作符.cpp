#include <stdio.h>

int main(void)
{
	// ȡ��~
	unsigned char a = 2;
	printf ("%d\n", ~a);  // һ����Ϊ2 �����ȡ��-2 ��ôֻ��ȡ����1  ����֤��ϵͳĬ������Ϊ�з���
	unsigned char aa = ~a;
	printf ("%d\n", aa);  // ��������aa���޷��ŵĻ���ô�ͻ�ȡ��253

	// �� ����
	unsigned int b = 65535;
	printf("%d\n", b);
	b &= 255;//0377;//0xff;
	printf("%d\n", b);

	// ��λ�����
	int num = 1;
	printf("%d\n", num);
	num <<= 2;
	printf("%d\n", num);
	int n = 4;
	printf("%d\n", n);
	n >>= 2;
	printf("%d\n", n);  // �����з��ŵĲ��㻹�ǲ�1ȡ����ϵͳ �����޷��ŵĶ��ǲ���

	return 0;
}
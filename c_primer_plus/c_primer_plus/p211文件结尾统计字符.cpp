// �����ϰ 1
// ���һ������, ͳ�ƴ����뵽�ļ���βΪֹ���ַ���
#include <stdio.h>
int main(void)
{
	int num_char = 0;

	while(EOF != getchar()) // ע��: ֻ�����е�һ���ַ�Ϊctrl+z������Ч����EOF
		num_char++;
	printf("�˴�����һ������%d���ַ�.", num_char);

	return 0;
}
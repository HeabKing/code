// scanf()��ȡʧ�ܺ��һֱ���Զ�ȡ���ǻ�ֱ�ӷ��ش�����ֵ
// δ����ȡ��ֵ�᲻�ᱻ�����´ζ�ȡ?   �ǵ�
// scanf()��ȡ����ȥ�᷵��0Ȼ����ִ�б���scanf()ֻ������Ӳ��������ߵ����ļ���β�Żط���EOF(-1)
#include <stdio.h>
int main(void)
{
	int in;
	char ch;

	printf("EOF = %d\n", EOF);
	printf("%d\n", scanf("%d", &in));
	scanf("%c", &ch);
	printf("%c\n", ch);
	

	return 0;
}
// ��ʾ����
#include <stdio.h>
int main(void)
{
	double dou = 8;
	char ch;
	int in;

	//printf("\\%d\\\n", scanf("%f", &dou));
	//printf("%lf\n", dou);
	// ���ݵ���dou�ĵ�ַ, ���Բ���������������ʽ������ת��
	// ���Ͳ�ƥ��,scanf()���Ƿ�����1, ˵�������˲��Ҵ�����

	printf("\\%d\\\n", scanf("%d", &in));
	printf("%d\n", in);
	// ������ĸ��scanf()���ص�ֵ��0

	//scanf("%lf", &dou);
	//printf("%lf", dou);

	return 0;
}
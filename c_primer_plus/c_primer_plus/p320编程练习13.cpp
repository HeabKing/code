// �����ϰ 11.13 (13)
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	double end = 1;

	if(argc > 2)
	{
		int i = atoi(argv[2]);     // ����Ķ����ı���ʽ, ���Բ���ֱ�Ӳ�������
		double dou = atof(argv[1]); // ����ҲҪ��
		while (i-- > 0)
			end *= dou;
	}
	else
	{
		puts("�������");
		getchar();
		exit(EXIT_FAILURE);
	}
	printf("%lf", end);
	getchar();

	return 0;
}
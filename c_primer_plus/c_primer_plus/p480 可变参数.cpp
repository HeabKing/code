// �����嵥 16.18
#include <stdio.h>
#include <stdarg.h>  // standard argument
double sum(int, ...);
int main(void)
{
	double s, t;

	s = sum(3, 1.1, 2.5, 13.3);  // 3 is argument list's arguments
	printf("return value for s is %g\n", s);
	//t = sum(6, 1, 2, 3, 4, 5, 6);  ��������ú�����Ķ���, û���Զ�������ת��, ���ܽ�intת��Ϊdouble
	t = sum (6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
	printf ("return value for t is %g\n", t);

	return 0;
}

double sum(int lim, ...)
{
	va_list ap;  // �������ڴ�Ų����ı���
	va_list apcopy;  // ����ĸ���
	double tot = 0;
	int i;
	va_start(ap, lim);  // ��ap��ʼ��Ϊ�����б�(�Ѳ����б��Ƶ�va_list()�����б���)
	va_start(apcopy, lim);
	for (i = 0; i < lim; i++)
		tot += va_arg(ap, double);  // ���ʲ����б��е�ÿ����Ŀ
				// ��һ�ε���ʹ�õ�һ����Ŀ, �ڶ��ε���ʹ�õڶ���, �������Ϊ��һ��ɾһ��
	printf("--%f--", va_arg(apcopy, double));
	va_end(ap);  // ������ eg: �ͷŶ�̬��������ڴ�Ų����Ķ�̬�ڴ�
	va_end(apcopy);
	return tot;
}
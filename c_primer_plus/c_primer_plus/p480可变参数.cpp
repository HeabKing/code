// �����嵥 16.18
#include <stdio.h>
#include <stdarg.h> // standard����׼��arguments��������
double sum (int, ...);
int main (void)
{
	double s, t;

	s = sum (3, 1.1, 2.5, 13.3); // 3�ǲ����б��в����ĸ���
	t = sum (6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
	printf ("return value for s is %g\n", s);
	printf ("return value for t is %g\n", t);

	return 0;
}

double sum (int lim, ...)
{
	va_list ap;   // �������ڴ�Ų����ı���
	va_list apcopy;
	double tot = 0;
	int i;
	va_start (ap, lim); // ��ap��ʼ��Ϊ�����б�(�Ѳ����б��Ƶ�va_list()�����б���)
	for (i = 0; i < lim; i++)
		tot += va_arg (ap, double); // ���ʲ����б��е�ÿһ����Ŀ
						// ��һ�ε���ʹ�õ�һ����Ŀ�ڶ���ʹ�õڶ��� �������Ϊ��һ��ɾһ�� ���ٴη���Ҫ��va_copy()??Ϊʲô��������֧��??
	va_end (ap); // ������
	return tot;
}
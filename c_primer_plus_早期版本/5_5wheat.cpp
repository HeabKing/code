//ָ������С���� �����ϵ�С����
//c primer plus �����嵥 5.5
//wheat.c -- ָ������
#include <stdio.h>
#define SQUARES 64  //�����ϵķ�����
#define CROP 1E15  //����ÿ��С��Ĳ���
int main (void)
{
	double current,total;
	int count = 1;

	printf ("square      grains added      total grains      fraction of US total\n");
	total = current =1.0;  //��ʼ��һ��
	printf ("%4d %18.2e %16.2e %19.2e\n", count, current, total,total/CROP);
	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current;  //��һ�����������
		total = total +current;  //�ܵ�����
		printf ("%4d %18.2e %16.2e %19.2e\n", count, current, total,total/CROP);
	}
	printf ("That's all.");
	return 0;
}
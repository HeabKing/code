//��������� ? :    //��������ת����ת������
//c primer plus �����嵥 7.8
//paint.c -- ʹ����������� paint:Ϳ��
#include <stdio.h>
#define COVERARE 200
int main (void)
{
	int sq_feet;
	int cans;

	printf ("Enter number of square feet to be painted: \n");
	while (scanf ("%d", &sq_feet) == 1)
	{
		cans = sq_feet / COVERARE;  //ͨ�� '�����β'  ���н���ת��
		cans += ((sq_feet % COVERARE == 0) ? 0: 1);   // ���������
		printf ("You need %d %s of paint.\n", cans, cans == 1 ? "can": "cans");  // ���������ѡ���������ַ���
		printf ("Enter next value (q to qiut): \n");
	}
	return 0;
}
// c primer plus �����嵥 9.10 p232
// hotel.c -- �ùݹ�����
// ��9.9����ģ�������
#include <stdio.h>
#include "9__11hotel.h"
int menu (void)
{
	int code, status;

	printf ("\n%s%s\n", STARTS, STARTS);
	printf ("Enter the number of the desired hotel: \n");
	printf ("1. Fairfield Arms  2. Hotel Olympic\n");
	printf ("3.Chertwothy Plaza  4. The Stockton\n");
	printf ("5. qiut\n");
	printf ("\n%s%s\n", STARTS, STARTS);
	// ���û���������Ĵ���
	while ((status = scanf ("%d", &code)) != 1 ||    // �����ǲ��Ƿ�int���ж�   // �õ�������ԭ��: 1. �߼����ʽ������������. 2. ֻ��ȷ����scanf()�Ѿ��ɹ������˲Ž���code�ļ��
		           (code < 1 || code > 5))           // int�ǲ���1-5���ж�
	{
		if (status != 1)
			scanf ("%*s");                           // ����Ƿ�int��ô���������, ��Ӱ���´ζ���, �����������������һ���հ��ַ�
		printf ("Enter an integer from 1 to 5, please.\n");
	}
	
	return code;
}

int getnights (void)
{
	int nights;

	printf ("How many nights are needed? ");
	// �ж��û��������Ƿ���Ϲ���
	while (scanf ("%d", &nights) != 1)
	{
		scanf ("%*s");
		printf ("Please enter an integer, such as 2.\n");
	}
	return nights;
}

void showprice (double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;

	for (n = 1; n <= nights; n++,factor *= DISCOUNT)
		total += rate * factor;
	printf ("The total cost will be $%0.2f.\n", total);
}
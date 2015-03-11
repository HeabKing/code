// p399 �����嵥 14.12
#include <stdio.h>
#include <stdlib.h>

struct flex {
	int count;
	double average;
	double score[];  // �����������Ա ǰ��������һ����ͨ��Ա
};

void showflex (struct flex * p);

int main (void)
{
	struct flex * pf1, * pf2;
	int n = 5;
	int i;
	double tot = 0;

	// Ϊ�ṹ��������䴢��ռ�
	pf1 =(struct flex *) malloc (sizeof (struct flex) + n * sizeof(double));
	pf1 -> count = n;
	for (i = 0; i < n; i++)
	{
		pf1 -> score[i] = 20.0 - i;
		tot += pf1 -> score[i];
	}
	pf1 -> average = tot / n;

	showflex (pf1);

	// ���ϴνṹ��С��ͬ�Ľṹ
	n = 9;
	tot = 0;
	pf2 =(struct flex *) malloc (sizeof (struct flex) + n * sizeof(double));
	pf2 -> count = n;
	for (i = 0; i < n; i++)
	{
		pf2 -> score[i] = 20.0 - i / 2.0;
		tot += pf2 -> score[i];
	}
	pf2 -> average = tot / n;
	showflex (pf2);

	// �ͷŷ����ڴ�
	free (pf1);
	free (pf2);

	return 0;
}

void showflex (struct flex * p)
{
	int i;
	printf ("scores: ");
	for (i = 0; i < p -> count; i++)
		printf ("%g ", p -> score[i]);
	printf ("\naverage: %g\n", p -> average);
}
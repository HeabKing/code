// p339 �����嵥 12.13 
#include <stdio.h>
#include <stdlib.h>        // Ϊrand()�ṩ����ԭ��
#include <time.h>          // Ϊtime()�ṩ����ԭ��
#include "p339������.h"	   // Ϊroll_n_dice()��roll_count�ṩ����ԭ��

int iii = 333;

int main (void)
{
	int dice, roll;
	int sides;

	srand ((unsigned int) time (0));    // ���������
	puts ("�������ӵ�����(����0�˳�):");
	while (scanf ("%d", &sides) == 1 && sides > 0)
	{
		puts ("Ҫ����������?");
		scanf ("%d", &dice);
		roll = roll_n_dice (dice, sides);
		printf ("��������%d��, �õ���%d��%d�������.\n", roll, dice, sides);
		puts ("�������ӵ�����(����0�˳�):");
	}
	printf ("�����һ������%d������.\n", roll_count);
	puts ("ok!");
	printf ("main:ii->>%d, iii - >> %d", ii, iii);
	return 0;
}
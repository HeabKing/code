// p338 �����嵥 12.11
#include <stdio.h>
#include <stdlib.h>       // Ϊrand()�ṩ���
#include "p339������.h"     // ""ָʾ�������ڱ���Ѱ���ļ�

int roll_count = 0;       // �ⲿ����
extern int iii;
static int rollem (int sizes)       // ����ļ���˽�к���
{
	int roll;

	roll = rand() % sizes +1;
	roll_count++;                   // ��¼�������õĴ���

	return roll;
}

int roll_n_dice (int dice, int sides)
{
	int d;
	int total = 0;
	
	if (sides < 2)
	{
		puts ("���ӵ���������Ϊ2!");
	
		return -2;
	}
	if (dice < 1)
	{
		puts ("������1������!");

		return -1;
	}
	for (d = 0; d < dice; d++)
		total += rollem(sides);
	ii = 321;
	iii = 222;
	printf ("roll_n_dece:ii->>%d, iii = %d", ii, iii);
	return total;
}
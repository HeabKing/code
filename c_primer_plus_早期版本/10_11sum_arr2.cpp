// ����,�����ָ��    ������ʽ����Ϊ����ĺ���������
// c primer plus �����嵥 10.11 p258
// sum_arr2.c -- ��һ�����������Ԫ�����
#include <stdio.h>
#define SIZE 10
int sum (int * start, int * end);     // int ar[]==int*ar -- ar��ָ��int��ָ��
int main (void)
{
	int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long answer;

	answer = sum (marbles, marbles + SIZE);
	printf ("The total number of marbles is %ld.\n", answer);
	printf ("The size of marbles is %u bytes.\n", sizeof marbles);  // marbles��10�ֽ�,��Ϊmarbles����10��int���͵���,ÿ����ռ�ĸ��ֽ�

	return 0;
}

int sum (int * start, int * end) // ʹ��ָ�������ȷ������Ŀ�ʼ��,ʹ����һ������ָ�������Ԫ�ظ���,������һ���������嵥10.11
{
	int total = 0;

	while (start < end)
	{
		total += *start;
		start++;
	}
	
	return total;
}
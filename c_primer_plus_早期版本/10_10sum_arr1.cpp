// ����,�����ָ��    ������ʽ����Ϊ����ĺ���������
// c primer plus �����嵥 10.10 p257
// sum_arr1.c -- ��һ�����������Ԫ�����
#include <stdio.h>
#define SIZE 10
int sum (int ar[], int n);     // int ar[]==int*ar -- ar��ָ��int��ָ��
int main (void)
{
	int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long answer;

	answer = sum (marbles, SIZE);
	printf ("The total number of marbles is %ld.\n", answer);
	printf ("The size of marbles is %u bytes.\n", sizeof marbles);  // marbles��10�ֽ�,��Ϊmarbles����10��int���͵���,ÿ����ռ�ĸ��ֽ�

	return 0;
}

int sum (int ar[], int n) // ʹ��ָ�������ȷ������Ŀ�ʼ��,ʹ����һ������ָ�������Ԫ�ظ���,������һ���������嵥10.11
{
	int i;
	int total = 0;

	for (i = 0; i < n; i++)
		total += ar[i];
	printf ("The size of ar is %u bytes.\n", sizeof ar);  // ar ֻ���ĸ��ֽ�,��Ϊ����4�ֽڵ�ַ�ļ����ϵͳ,ָ��Ĵ�СΪ4�ֽ�,arΪָ��marbles����Ԫ�ص�ָ��

	return total;
}
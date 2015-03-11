// �����嵥 16.17
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
void showArray(const int ar[], int n);
int main(void)
{
	int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int target[SIZE];
	double curious[SIZE / 2] = {1.0, 2.0, 3.0, 4.0, 5.0};

	puts("*memcpy() used:");  // �������Ƿ����ص���, ����еĻ������δ֪��
	puts("values (original data): ");  // original data ԭʼ����
	showArray(values, SIZE);
	memcpy(target, values, SIZE * sizeof(int));
	puts("target(copy of values): ");
	showArray(target, SIZE);
	
	puts("\nUsing memmove() with overlapping ranges: ");
	memmove(values + 2, values, 5 * sizeof(int));
	puts("values -- elements 0-5 copied to 2-7: ");
	showArray(values, SIZE);

	// ˵��memcpy()�����ĸ��Ƶ���������
	puts("\nUsing memcpy() to copy double to int: ");
	memcpy(target, curious, (SIZE / 2) * sizeof(double));
	puts("target -- 5double into 10 int positions: ");
	showArray(target, SIZE);

	return 0;
}

void showArray(const int ar[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
		if (i % 6 == 5)
			puts("");
	}
	if (i % 6 != 0)
		puts("");
}
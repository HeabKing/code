#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void choujiang(int [], int, int);

int main(void)
{
	int ar[10];
	for (int i = 0; i < 10; i++)
		ar[i] = i+1;
	choujiang(ar, 10, 8);

	return 0;
}

void choujiang(int ar[], int arrSize, int num)
{
	int i, choice, temp;
	srand(time(0));
	if (num > arrSize)
	{

		puts("��ѡ����������, ���ص�������ʾ���������");
		num = arrSize;
	}
	for (i = 0; i < num; i++)
	{
		choice = rand() % (arrSize - 1);
		printf("%2d ", ar[choice]);
		if (i % 3 == 2)
			putchar('\n');
		temp = ar[choice];
		ar[choice] = ar[arrSize - 1];  // ���������е�ÿ����ֻ�ܳ���һ�ε����ѡȡ, ��ʹ�ù������ŵ������βȻ�����������Ǹ������ѡ��
		ar[arrSize - 1] = temp;
		arrSize--;
	}
	if (i % 20 != 0)
		putchar('\n');
}
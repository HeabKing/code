// p352 �����ϰ 6 ͳ��1000��0-9���������Ĵ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 1000
#define SIZE 10

int main (void)
{
	int ra[SIZE] = {0}, temp;
	int i;
	srand ((unsigned int) time (0));   // ����ΪʲôҪ����for������??????????
	for (i = 0; i < COUNT; i++)
	{
		
		temp = rand () % 10;
		printf ("%3d", temp);
		if ((i + 1) % 23 == 0)        // i+1��Ϊ�˷�ֹ0%23== 0�ľ���
			puts ("\n");
		ra[temp]++;
	}
	for (i = 0; i < SIZE; i++)
		printf ("\n%d -- >> %d\n", i, ra[i]);

	return 0;
}
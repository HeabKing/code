// p271 �����嵥 10.17
#include <stdio.h>
#define ROWS 3
#define COLS 4

void sum_rows (int ar[][COLS], int rows);    // ����д��int ar[][]�ǲ��Ե�, ��Ϊ������ʱϵͳ��Ҫ֪��ָ����ָ������ֽ���, ar[1] == ar + 1;������4��intҲ����16�ֽ�
void sum_cols (int (* ar)[COLS], int rows);
int sum2d (int [][COLS], int rows);         

int main (void)
{
	int junk[ROWS][COLS] = {
			{2, 4, 6, 8},
			{3, 5, 7, 9},
			{12, 10, 8, 6}
	};

	sum_rows (junk, ROWS);
	sum_cols (junk, ROWS);
	printf ("Sum of all element is %d.\n", sum2d (junk, ROWS));   // element Ԫ��

	return 0;
}

void sum_cols (int ar[][COLS], int rows)  // �����COLS�����˱�����arָ��ָ��Ķ����С  ar+1ʱ��֪����ô����
{
	int r;
	int c;
	int tot;
	
	for (r = 0; r < rows; r++)
	{
		tot = 0;
		for (c = 0; c < COLS; c++)
			tot += ar[r][c];
		printf ("row:%d, sum:%d\n", r, tot);
	}
}

void sum_rows (int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	
	for (c = 0; c < COLS; c++)
	{
		tot = 0;
		for (r = 0; r < rows; r++)
			tot += ar[r][c];
		printf ("cols:%d, sum:%d\n", c, tot);
	}
}

int sum2d (int (* ar)[COLS], int rows)
{
	int r;
	int c;
	int tot = 0;
	
	for (c = 0; c < COLS; c++)
		for (r = 0; r < rows; r++)
			tot += ar[r][c];
	
	return tot;
}
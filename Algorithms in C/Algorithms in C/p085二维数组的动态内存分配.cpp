#include <stdio.h>
#include <stdlib.h>
#define N 3
int **malloc2d(int r, int c)
{
	int i;
	int **t = (int **)malloc(r * sizeof(int *));
	for (i = 0; i < r; i++)
		t[i] = (int *)malloc(c * sizeof(int));
	return t;
}
int main(void)
{
		// ��̬�ڴ�����ά���� δ�ɹ��ķ���

	int * b = (int *)malloc(N * N * sizeof(int));	// ��̬����b[N * N]
	for (int i = 0; i < N*N; i++)
		b[i] = i;
	int ** bb = (int **)b;
	//printf("%d ", bb[0][0]);	// Error

	//typedef int *typeCast[3];
	
	//typeCast bbb = (typeCast)b;

		// ��̬�����ά���� ��ȷ�ķ���

	int **a = malloc2d(N, N);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			a[y][x] = x + y;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
			printf("%d ", a[y][x]);
		printf("\n");
	}


	return 0;
}
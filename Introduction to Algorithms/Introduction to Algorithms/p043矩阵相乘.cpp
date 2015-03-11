// ������һ��������˵��㷨
#include <iostream>
using namespace std;

#define �����㷨

#ifdef �����㷨

void matrixMultiply(const int * A, const int * B, int n)
{
	// ��ά���鶯̬�ڴ����
	int ** AA = (int **)malloc(sizeof (int *) * n);
	int ** BB = (int **)malloc(sizeof (int *) * n);
	int ** CC = (int **)malloc(sizeof (int *) * n);
	for (int i = 0; i < n; i++)
	{
		AA[i] = (int *)malloc(sizeof (int) * n);
		BB[i] = (int *)malloc(sizeof (int) * n);
		CC[i] = (int *)malloc(sizeof (int) * n);
	}

	// ��ֵ
	for (int i = 0; i < n * n; i++)
	{
		AA[i % n][i / n] = A[i];
		BB[i % n][i / n] = B[i];
		CC[i % n][i / n] = 0;
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
			cout << AA[y][x] << " ";
		cout << endl;
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
			cout << BB[y][x] << " ";
		cout << endl;
	}

	// ����˻�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				CC[i][j] += AA[i][k] * BB[k][j];

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
			cout << CC[y][x] << " ";
		cout << endl;
	}
}

int main(void)
{
	int A[] = {	1, 2,
				2, 3 };
	int B[] = { 2, 3, 
				3, 4 };

	matrixMultiply(A, B, 2);

	return 0;
}

#else

#endif
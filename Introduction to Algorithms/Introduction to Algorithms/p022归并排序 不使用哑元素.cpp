// ϰ�� 2.3-2
#include <iostream>
using namespace std;

	// �������źõ�Ԫ�����кϲ���һ���ź��������
void Merge(int * A, int front, int mid, int rear);

	// ������, ��һ�������ź���, ������Ƕ��Merge, ����Ҫ������, һֱ��ֵ�ֻ��һ��Ԫ��, ��ͳ����ź������
void MergeSort(int * A, int f, int l);

int main(void)
{
	const int SIZE = 1000;
	int A[SIZE];

	for (int i = 0; i < SIZE; i++)
		A[i] = rand() % 1000;
	for (int i = 0; i < SIZE; i++)
		cout << A[i] << " ";
	cout << endl;

	MergeSort(A, 0, SIZE - 1);

	cout <<endl;
	for (int i = 0; i < SIZE; i++)
		cout << A[i] << " ";

	return 0;
}

void MergeSort(int * A, int f, int l)
{
	if (f >= l)	// ������ڻ����һ��Ԫ��, �Ͳ��÷���, ֱ�ӿ�ʼ����
		return;
	int m = (f + l) / 2;	// (l - f + 1) / 2; !!!!!!!!!!!!!! ������д���Ƚ� !!!!!!!!!!!!!!!!!!!
	MergeSort(A, f, m);
	MergeSort(A, m + 1, l);
	Merge(A, f, m, l);
}

void Merge(int * A, int f, int m, int l)
{
		// ���ڴ�
	int Num1	= m - f + 1;	// �������Ԫ�ظ���
	int Num2	= l - m;		// �������Ԫ�ظ���
	int * L		= new int[Num1];// ��ʹ����Ԫ��, ���ø��������ڴ�
	int * R		= new int[Num2];

		// ��ֵ
	for (int i = 0; i < Num1; i++)
		L[i] = A[f + i];
	for (int i = 0; i < Num2; i++)
		R[i] = A[m + 1 + i];

		// �ϲ�
	for (int iL = 0, iR = 0, iA = f; ; )
	{
		if (iL >= Num1)	// ������Ԫ��ȡ����, ֱ�ӽ���辸���A
		{
			for (int i = iR; i < Num2; i++)
				A[iA++] = R[i];
			break;
		}
		if (iR >= Num2)	// ������Ԫ��ȡ����
		{
			for (int i = iL; i < Num1; i++)
				A[iA++] = L[i];
			break;
		}
		if (L[iL] < R[iR])
			A[iA++] = L[iL++];
		else
			A[iA++] = R[iR++];
	}
}
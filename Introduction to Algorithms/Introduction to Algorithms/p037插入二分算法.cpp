// ϰ��2.3-6 ��2.1�Ĳ����㷨��5-7�еĲ��Ҹĳɶ��ֲ���
// ʱ�临�Ӷ���n^2
#include <iostream>
using namespace std;

void InsertionSort(int * A, int len);
	// ���v�ڸ���������, ���ش�ֵƫ����, ���v���κ�Ԫ�ض���, ��������Ԫ�����һ��ƫ����+1, ���v���κ�Ԫ�ض�С, ���صĲ��ǵ�һ��Ԫ�ص�ƫ����-1, ����Ϊ�˲���ķ���, ��һ����Э
int  BinarySearch(int * Ar, int p, int r, int v);	// p�ǿ�ʼԪ��ƫ����, !r��Ar��Ԫ�ظ���!

int main(void)
{
	const int SIZE = 100;
	int A[SIZE];
	int N	= sizeof A / sizeof *A;
	for (int i = 0; i < N; i++)
		A[i] = rand() % 100;
	InsertionSort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";

	return 0;
}

void InsertionSort(int * A, int len)
{
	for (int i = 1, r = 0; i < len; i++)
	{
		int j = BinarySearch(A, r, i, A[i]);	// ����Ѱ��A[r, i-1]��A[i]���ʵ�λ��

			// ��A[i]����������ʵ�λ��, ����������Ӧ��Ԫ�غ���
		int temp = A[i];						// ��Ȼ������clgn, ���������е�λ���ƶ�����cn, �������������Ļ�����Ч���ϵļ������, �������, ʱ�临�ӶȲ���, ��������������...
		for (int m = i; m > j; m--)
			A[m] = A[m-1];
		A[j] = temp;
	}
}

int BinarySearch(int * A, int p, int r, int v)
{
	if (p >= r)
	{
		cout << "Error: Wrong parameters of BinarySearch function, should be p <= r!\n";
		exit(EXIT_FAILURE);
	}
	if (p + 1 == r)						// ��ʱ���ҵ�״̬��p + 1 = q, ����˼·��, p������Ԫ����0, r��Ԫ�ظ�����1, Ȼ���ʱ���е���ֻ��һ��Ԫ�ص�״̬
	{
		if (v <= A[p])					// ���v��A[p]�����, ����v == A[p]
			return p;
		else if (v > A[p])				// ���v��A[p]���ұ�
			return r;
	}
	int m = (p + r) / 2;
	if (A[m] == v)	// ��ĳ�ζ����������ҵ���һ�����ֵ
		return m;
	else if (v > A[m])			// ���������������, ��һֱ�ݹ���ȥ
		return BinarySearch(A, m, r, v);
	else
		return BinarySearch(A, p, m, v);
}
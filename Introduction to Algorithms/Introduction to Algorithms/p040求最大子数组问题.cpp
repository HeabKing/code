// ��һ�������е��������
// 140716 ���õĵط�	1. SubarrayFlagTag FindCrossingSubarray(int * A, int L, int R)�ȵط�R�����ҽ�����ҽ��һλ, ����߼�����
//						2. for (int i = M - 1; i >= L; i--) 	#1  �����õ���M - 1 ����ʾ��벿��, �����в���, Ҳ��ͨ���߼�����, ��øĳ� [L, M]�� [M + 1, R]��
#include <iostream>
using namespace std;
int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
int N	= sizeof A / sizeof *A;
#define ��������

#ifdef ��������

int main(void)
{
		// ��������

	int L = 0, R = 1, MaxTemp = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			int temp = 0;
			for (int m = i; m <= j; m++)
				temp += A[m];
			if (temp > MaxTemp)
			{
				MaxTemp = temp;
				L = i;
				R = j;
			}
		}

	cout << "[" << L << "," << R << "]\n";
}

#else

	// ʹ�÷��β���

		// �������λ�õ����ݽṹ

struct SubarrayFlagTag
{
	int L;		// ��С����������
	int R;		// ������
	int MaxVal;	// ֵ
};

		// �����������е�����

SubarrayFlagTag FindCrossingSubarray(int * A, int L, int R)
{
	int M = (L + R) / 2;	// �е�����

			// CrossingSubarray����벿�ּ���

	int LMaxSum	= -111;	// ����׼��ʹ����һ��-111
	int temp	= 0;
	int LTemp;
	for (int i = M - 1; i >= L; i--)	// # 1 140716
	{
		temp += A[i];
		if (temp > LMaxSum)
		{
			LMaxSum	= temp;
			LTemp	= i;
		}
	}

			// �Ұ벿��

	int RMaxSum	= -111;
	int RTemp;	
	temp = 0;
	for (int i = M; i < R; i++)
	{
		temp += A[i];
		if (temp > RMaxSum)
		{
			RMaxSum	= temp;
			RTemp	= i + 1;	// ��������˼�һ
		}
	}

	SubarrayFlagTag tempSubarray = {LTemp, RTemp, LMaxSum + RMaxSum};
	return tempSubarray;
}

SubarrayFlagTag FindSubarray(int * A, int L, int R)
{
	
	if (L == R - 1)
	{
		SubarrayFlagTag tempSubarray = {L, R, A[L]};
		return tempSubarray;
	}
	else
	{
		int M = (L + R) / 2;
		SubarrayFlagTag LSubarray = FindSubarray(A, L, M);
		SubarrayFlagTag RSubarray = FindSubarray(A, M, R);
		SubarrayFlagTag MSubarray = FindCrossingSubarray(A, L, R);
		if (LSubarray.MaxVal >= RSubarray.MaxVal && LSubarray.MaxVal >= MSubarray.MaxVal)
			return LSubarray;
		else if (RSubarray.MaxVal >= LSubarray.MaxVal && RSubarray.MaxVal >= MSubarray.MaxVal)
			return RSubarray;
		else
			return MSubarray;
	}
}

int main(void)
{
	SubarrayFlagTag Subarray = FindSubarray(A, 0, N);

	cout << "[" << Subarray.L << ", " << Subarray.R - 1 << "]\n";

	return 0;
}

#endif
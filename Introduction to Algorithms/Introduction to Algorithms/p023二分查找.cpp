// ϰ��2.3-5	���ֲ���(Binary Search)
// ���ֲ��ҵ�ʱ�临�Ӷ���: lgn
#include <iostream>
using namespace std;
#define �ݹ�ʵ��	
//#define ����ʵ��

#ifdef �ݹ�ʵ��
int BinarySearch(int * A, int L, int R, int V);

int main(void)
{
	int A[] = {1, 3, 5, 6, 7, 8, 19};
	int N = sizeof A / sizeof *A;
	int L = 0, R = N;
	int V = 7;
	int M = BinarySearch(A, L, R, V);
	if (M == -1)
		cout << "A�����в�����" << V << endl;
	else
		cout << V << "�������е�A[" << M << "]\n";
}

int BinarySearch(int * A, int L, int R, int V)
{
	if (L == R-1 && A[L] != V)	// �������L R����, ��ʱM = (L + R) / 2 = L; ��A[L] != V, ���´ε���L R��ֵ����, ������������, ����Ӧ���˳�
	{
		V = -1;
		return V;
	}
	int M = (L + R) / 2;
	if (V < A[M])
		return BinarySearch(A, L, M, V);
	else if (V > A[M])
		return BinarySearch(A, M, R, V);
	else	// V == A[M]
		return M;
}
#elif defined ����ʵ��

int main()
{
	int V = 10;
	int A[] = {1, 3, 6, 8, 9};
	int N = sizeof A / sizeof *A;

	int M;
	for (int L = 0, R = N;;)
	{
		M = (L + R) / 2;
		if (L == M && A[M] != V)	// ������V
		{
			M = -1;
			break;
		}
		if (A[M] == V)
			break;
		else if (A[M] > V)
			R = M;
		else if (A[M] <= V)
			L = M;
	}
	if (M == -1)
		cout << "A�����в�����" << V << endl;
	else
		cout << V << "�������е�A[" << M << "]\n";

}

#endif
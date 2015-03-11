#include <iostream>
#include <cstdlib>
#define YA -1

	// �������Ѿ��ź����������ϳ�һ���ź��������
void MERGE(int * A, int p, int q, int r);	// A[p, q], A[q+1, r] rs���ܹ�ȡ����
void MERGE_SORT(int * A, int p, int r);

int main(void)
{
	const int SIZE = 1023;
	int A[SIZE];
	for (int i = 0; i < SIZE; i++)
		A[i] = rand() % 100;

	std::cout << "����ǰ: \n";
	for (int i = 0; i < SIZE; i++)
		std::cout << A[i] << ' ';

	std::cout << "\n������... \n";
	MERGE_SORT(A, 0, SIZE-1);

	std::cout << "\n�����: \n";
	for (int i = 0; i < SIZE; i++)
		std::cout << A[i] << ' ';

	std::cout << std::endl;
	return 0;
}

void MERGE(int * A, int p, int q, int r)
{

		// ����辷����ڴ�

	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];	// + 1 ������Ԫ��
	int *R = new int[n2 + 1];

		// ������A��δ����Ĳ��ֳַ������ֱַ𱣴浽���������

	for (int i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[q + 1 + i];
	
	L[n1] = YA;	// ��Ԫ�ر�ʶ���еĽ�β
	R[n2] = YA;

		//	���������н�������ϲ�, ���ź�������з���A��

		// �ȽϵĽ����A[p, r]�е�����Ԫ�ض�����ֵ��, ���ԱȽ���r-p+1��, �����������YA == L[i] && YA == R[j]��ʱ����������ѭ���Ŷ�, ����k++������for�ж�����ÿ��ʹ��A[k++] = ..
	for (int k = p, i = 0, j = 0; k <= r; k++)
	{
		if ((YA == R[j] && YA != L[i]) || // �����һ������ȡ��, ������Ԫ��
			(L[i] <= R[j] && YA != L[i] && YA != R[j]))	// ����������ж�û��ȡ��, ��Ӧ�ñ�֤�Ƚ�Ԫ�ز�����Ԫ��
			A[k] = L[i++];
		else if ((YA == L[i] && YA != R[j]) || (R[j] < L[i] && YA != L[i] && YA != R[j]))
			A[k] = R[j++];
	}
}

void MERGE_SORT(int * A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;		
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q+1, r);
		MERGE(A, p, q, r);
	}
}
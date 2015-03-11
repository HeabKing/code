// ��ϰ 2.3-4
// �ȵݹ�����A[n]�е�A[n-1]����, Ȼ�󽫵�n�������ȥ
#include <iostream>
using namespace std;

	// ����ݹ�ĺ���
void InsertSort(int * A, int len);
	// �������ĺ���
void Insert(int * A, int len);	// len��Ҫ�������, 0 ~ len-1���Ѿ��ź����

int main(void)
{
	const int SIZE = 1000;
	int A[SIZE];

	for (int i = 0; i < SIZE; i++)
		A[i] = rand() % 1000;
	for (int i = 0; i < SIZE; i++)
		cout << A[i] << " ";
	cout << endl;

	InsertSort(A, SIZE);

	cout <<endl;
	for (int i = 0; i < SIZE; i++)
		cout << A[i] << " ";

	return 0;
}

void InsertSort(int * A, int len)
{
	if (len <= 1)	// һֱ�ݹ鵽ֻʣһ��Ԫ�ص�ʱ���˳�
		return;
	InsertSort(A, len-1);
	Insert(A, len);
}

void Insert(int * A, int len)
{
	for (int i = len - 2, temp, j = len - 1; i >= 0; i--, j--)
	{
		if (A[j] >= A[i])
			break;
		temp = A[j];
		A[j] = A[i];
		A[i] = temp;
	}
}
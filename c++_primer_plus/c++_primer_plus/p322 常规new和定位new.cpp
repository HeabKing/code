// ע��: ��λnew������ڴ治����delete�ͷ�, ��ֻ�ܷ��������

#include <iostream>
#include <new>  // for ��λnew�����
using namespace std;

const int	N	= 5;
const int	BUF	= 512;
char		buffer[BUF];

int main(void)
{
	double * pd1, * pd2;

		// ��һ�ε���new�Ͷ�λnew

	cout << "����new�Ͷ�λnew:\n";
	pd1 = new double[N];			// pd1 ָ����з�����ڴ�
	pd2 = new (buffer) double[N];	// pd2 ָ��buffer���׵�ַ
	for (int i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "�ڴ��ַ: \n" << "���� : " << pd1
		<< "   ��̬��: " << (void *)buffer << endl;  // ����bufferָ������ַ���, ��������Ҫת���ɿ�ָ�����ʹ����ʾָ��������ַ���
	cout << "�ڴ��а���: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";\t";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

		// �ڶ��ε���

	double * pd3, * pd4;

	cout << "\n�ڶ��ε���new�Ͷ�λnew:\n";
	pd3 = new double[N];			// Ѱ���µĶ��ڴ�
	pd4 = new (buffer) double[N];	// ����ԭʼ����
	for (int i = 0; i < N; i++)
		pd4[i] = pd3[i]= 1000 + 40.0 * i;
	cout << "�ڴ��а���: \n";
	for (int i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << ";\t";

				// ���ｫpd4�ĳ�pd2һ��ʹ��, ��Ϊ����ʹ�����˸���û���ͷ�pd2, ���������Ƕ�λ����ͬһ��λ��
				// ���������ǲ���������ͷ�pd2��, �ͷ��˵Ļ�pd4��ôָ�򲻴��ڵ��ڴ���, �ǰ�, ���Ǳ��������������ͷŵ�ʱ�򱨴�����Ǻ�֪�������ʹ��pd4��ʱ��ű���;
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

		// �����ε���
	delete [] pd1;	// �ͷ��ڴ�, ��ֹҰ�ڴ浼���ڴ�й¶
					// ֮���Է�����������Ƿ���һʹ������ͷŵ�λ������Ϊʹ������ͷŵĻ������pd3���ֻ�ʹ�������ַ, ��ʱ�����һ��ʹ�õĵ�ַ�ԱȲ�����
	cout << "\n�����ε���new�Ͷ�λnew:\n";

	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (int i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "�ڴ��а���:\n";
	for (int i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";\t";  // �����pd1�ͷ���һ��, Ȼ���ٷ����ʱ���ְ�ͬ���ĵ�ַ���������, ������ʱ��ע�⵽pd3��û���ͷ�, ����pd3�Ǳ�pd1������, �����ڷ����ʱ��ȴ����pd3ǰ�������һ��pd1, ��Ҳ˵���˶ѵ��ڴ����ʽ
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete []pd1;
	delete []pd3;

	return 0;
}
// �����嵥 9.10
// ע���ں����ڲ�new�ı����ڸú���ִ�����new�ı���������, �����ں�������������ָ��ᱻ����, ����С��new���ڴ��ΪҰ�ڴ�
#include <iostream>
#include <new>  // for placement new (Ϊ��λnew������ṩԭ��)
const int N = 5;
const int BUF = 512;
char buffer[BUF];  // chunk(����һ��) of memory
int main()
{
	using namespace std;
	double *pd1, *pd2;
	int i;
	cout << "Calling new and placement new:\n";
	pd1 = new double[N];  // use heap(��)
	pd2 = new (buffer) double[N];  // use buffer array
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "Memory addresses:\n" << " heap: " << pd1
		<< " static: " << (void *) buffer << endl;  // bufferΪchar *����, ������ʾ���ַ, ���Լ�����void*
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";\t";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	//delete [] pd2;   // ����new����(ȷ�е�˵��ѡ��)���ڴ治����delete�ͷ�!!!!!!
					 // ȷ�е�˵��bufferָ�����ڴ��Ǿ�̬�ڴ�, ��deleteֻ������������ָ��: ָ�򳣹�new���������Ķ��ڴ�

	cout << "\nCalling new and placement new a second time:\n";
	double *pd3, *pd4;
	pd3 = new double[N];          // find new address
	pd4 = new (buffer) double[N];  // overwhrite old data
	for (i = 0; i < N; i++)
		pd3[i] = pd4[i] = 1000 + 40.0 * i;
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << ";\t";
		cout << pd4[i] << " at " << &pd4[i] << endl;  // ��������û���ͷ�pd2��������ʹ��pd2Ҳ�ܴ�ɸ�ʹ��pd4һ����Ч��
												  // ���ǲ��ܹ��ͷ�pd2, ��Ϊ�ͷ���pd2�Ժ�pd4�Ͳ������� �����ͷ�����ǻᵼ�³����쳣��ֹ��(�ͷŵ�ʱ����ֹ������ʹ��pd4��ʱ����ֹ)
	}

	cout << "\nCalling new and placement new a third time:\n";
	delete [] pd1;  // �ͷ��ڴ�, ��ֹҰ�ڴ浼���ڴ�й¶
				   // ֮���Է�����������Ƿ���һʹ������ͷŵ�λ������Ϊʹ������ͷŵĻ������pd3���ֻ�ʹ�������ַ, ��ʱ�����һ��ʹ�õĵ�ַ�ԱȲ�����
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << ";\t";  // �����pd1�ͷ���һ��, Ȼ���ٷ����ʱ���ְ�ͬ���ĵ�ַ���������, ������ʱ��ע�⵽pd3��û���ͷ�, ����pd3�Ǳ�pd1������, �����ڷ����ʱ��ȴ����pd3ǰ�������һ��pd1, ��Ҳ˵���˶ѵ��ڴ����ʽ
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete [] pd1;
	delete [] pd3;

	return 0;
}
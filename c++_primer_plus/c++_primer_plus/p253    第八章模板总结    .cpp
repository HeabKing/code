// �Լ��ܽ�
// 1. ����ģ��ľ��廯(��ʾʵ����, ��ʽʵ����, ��ʾ���廯)
// 2. ����ģ�������
// 3. decltype
// 4. ������������

#include <iostream>
using namespace std;

template<typename T>
void Swap(T a, T b)  // δ��ʵ�ֽ���, Swap<int &>(a, b);  // ����,  T temp ת����int & temp�Ļ�û�г�ʼ��;
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template <typename T>
void Swap2(T & a, T & b)
{
	T temp;
	temp = a; 
	a = b; 
	b = temp;
}
template<typename T>
void Swap3(T * a, T * b)
{
	T temp;
	temp = *a; 
	*a = *b; 
	*b = temp;
}
template void Swap2<char>(char &, char &);  // ��ʾʵ����

template<class T1, class T2>
auto xy(T1 x, T2 y) -> decltype(x + y)
{
	decltype(x + y) result = x + y;
	return result;
}

int main(void)
{
	
	int a = 0;
	int b = 1;
	cout << a << b << endl;
	Swap(a, b);  // ��ʽʵ����
	cout << a << b << endl;
	//Swap<int &>(a, b);  // ����,  T temp ת����int & temp�Ļ�û�г�ʼ��;
	//cout << a << b << endl;
	Swap2(a, b);
	cout << a << b << endl;

	char aa = 'a';
	char bb = 'b';
	cout  << aa << bb << endl;
	Swap2(aa, bb);  // ʹ����ʾʵ����
	cout  << aa << bb << endl;

	int aaa = 000;
	double bbb = 111;
	cout << aaa << bbb << endl;
	Swap<double>(aaa, bbb);
	//Swap2<double>(aaa, bbb);  // ��ʾʵ��������2����ʵ��double & ����ָ��ǿ������ת��int����aaaΪdouble��aaa;
	cout << aaa << bbb << endl;
	// Swap2((double &)aaa, bbb); // �������
	// cout << aaa << bbb << endl;

	//Swap3<double>(&aaa, &bbb);  // ��ʾʵ��������2����ʵ��double * ����ָ��ǿ������ת��int����aaaΪdouble��aaa;
	//Swap3((double *)&aaa, &bbb);
	//cout << aaa << bbb << endl;  // �������

	int x = 2;
	double y = 3.023;
	cout << xy(x, y) << endl;

	return 0;
}
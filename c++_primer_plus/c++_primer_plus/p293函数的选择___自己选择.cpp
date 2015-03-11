// �����嵥 8.15
#include <iostream>

auto lesser (int a, int b) -> int          // #2
	// �����������Ƶ�������������  -> int ����Ϊ���÷�������
	// auto��һ��ռλ��, ��ʾ���÷��������ṩ������
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}
template<class T> T lesser(T a, T b) // #1
{
	return a < b ? a : b;
}

int main()
{
	using namespace std;
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;

	cout << lesser(m, n) << endl;      // use #2
	cout << lesser(x, y) << endl;      // use #1
	cout << lesser<>(m, n) << endl;    // use #1
		// <>ָ��������Ӧ��ѡ��ģ�庯�������Ƿ�ģ�庯��
	cout << lesser<int>(x, y) << endl; // use #1
		// �������Ҫ�������ʾʵ����(ʹ��int����T), ��ʹ����ʾʵ�����õ��ĺ���, x��y��ǿ��ת��Ϊint, �ú�������һ��int

	return 0;
}
// �����嵥 8.11
#include <iostream>
template <typename T> // template ģ�� // ������class����typename
void Swap(T &a, T &b);
// ģ�岻�ᴴ���κκ���, ֻ�Ǹ��߱�������ζ��庯��, ��Ҫ����int������ʱ��, ���������ᰴģ��ģʽ���������ĺ���, ����int����T
// ����ģ�岻�����̿�ִ�г���, �����Խ������������ĺ�������, �������ֹ���ʽ��������Щ����һ��, ���մ��벻�����κ�ģ��

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i, j);
	cout << "Now j, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(x, y);
	cout << "Now x, y = " << x << ", " << y << ".\n";

	return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
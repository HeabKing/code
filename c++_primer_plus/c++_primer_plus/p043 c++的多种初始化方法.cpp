#include <iostream>
using namespace std;

int main(void)
{
	int aa = 1;
	char b('b');
	float c = {1.1f};
	//double d = {};
	//int f{2};
	//double d{2.2};
	//double d{};

	cout << aa << endl << b << endl << c << endl;
	cout << sizeof(int) << endl << sizeof(long) << endl << sizeof(long long) << endl;
	int a = 65536;
	cout << "���ҵĵ�����, intΪ4�ֽ�32λ, �ܹ�����" << a << endl;
	cout << "������INT_MAX��ֵΪ" << INT_MAX << endl;

	return 0;
}
// �Լ��ܽ�
#include <iostream>
int main()
{
	using namespace std;
	int a = 0, b = 0;
a: std::cout << a << endl; // ��һ��ִ�е������ʱ������
	cout << b << endl;
	b++;
	a = 2;
	while ( b < 3 )
		goto a;

	return 0;
}
// �����嵥 5.5
// �ĳ��������û��޸ĳ���ִ�еĴ���, ����i�ĵ����ݶ�
#include <iostream>
int main()
{
	using std::cout; // һ��ʹ������
	using std::cin;  // ���ֵ���using����������using namespace std����ָ��
	using std::endl;
	cout << "Enter an integer: \n";
	int by;
	cin >> by;
	cout << "Counting by " << by << "s:\n";
	for (int i = 0; i < 100; i = i + by)
		cout << i << endl;

	return 0;
}
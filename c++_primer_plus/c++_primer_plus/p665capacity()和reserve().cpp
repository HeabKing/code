#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "Sizes:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\telarger: " << larger.size() << endl;
	cout << "Capacities:\n";
	cout << "\tempty: " << empty.capacity() << endl;  // ���ص�ǰ���ڴ�����Ŀռ�Ĵ�С
	cout << "\tsmall: " << small.capacity() << endl;  // ��ʵ����С����Ϊʮ����ַ�
	cout << "\telarger: " << larger.capacity() << endl;
	empty.reserve(50);  // �����ڴ�����С����
	cout << "Capacity after empty.reserve(50): " << empty.capacity() << endl;
}
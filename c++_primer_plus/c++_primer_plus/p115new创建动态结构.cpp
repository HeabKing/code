// �����嵥 4.21
// new������̬�ṹ����->���ʶ�̬�ṹ
#include <iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable * ps = new inflatable;
	cout << "Name:\n";
	cin.get(ps->name, 20); // ��ȡһ�������19���ַ�, �������з���ֹͣ����, �ѻ��з�������������
	cout << "Volume:\n";
	cin >> (*ps).volume;
	cout << "Price:\n$";
	cin >> ps->price;
	cout << "Name: " << ps->name << endl;
	cout << "Volume: " << ps->volume << endl;
	cout << "Price: $" << ps->price << endl;
	delete ps;

	return 0;
}
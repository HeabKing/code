// �����嵥 9.5 (���������嵥9.6)
#include <iostream>
static int i; // ����9.6���Ѿ������˾����ⲿ���ӵ�int i��������ֱ������int i���ᱻ��Ϊ�Ƕ��ζ���, ��������Ϊ�����ڲ����ӵ�ȫ�ֱ����ǿ��Ե�, ���һ����ؾ����ⲿ���ӵ�ͬ������
using namespace std;
// extern variable
double warming = 0.3;
// function prototypes
void update(double);
void local();

int main()
{
	cout << "Global warming is " << warming << " degrees.\n";
	update(0.1);
	cout << "Global warming is " << warming << " degrees.\n";
	local();
	cout << "Global warming is " << warming << " degrees.\n";

	return 0;
}

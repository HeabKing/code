#include <iostream>
using namespace std;
void fun(const int &a)
{
	cout << a << endl;
}
void fun2(int &a)
{
	cout << a << endl;
}
int main(void)
{
	const int aa = 1;
	int & bb = aa;  // ����Ϊconst����������const����
	const int & bbb = aa;
	const int & bbbb = 3; // ��������ʱ���� 
	fun(3);  // ����������һ����ʱ����, ����a����ʱ�����ı���;
	fun2(2);  // ���ﲻ��������ʱ����
	//	������ʱ�����Ĺ���:
	//		1. ���ò�����const
	//		2. ʵ�ε�������ȷ, ���ǲ�����ֵ;
	//		3. ʵ�����Ͳ���ȷ, ���ǿ���ת������ȷ����;
	fun(aa);
	fun2(aa);  // ���ﲻ�ܽ������޸ĵ���ֵ��ֵ����const����
}
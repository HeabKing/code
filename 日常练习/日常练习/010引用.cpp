#include <iostream>
int main()
{
	using namespace std;
	int a[10];
	// a++;  // ����, ��Ϊ����const int *
	int *const(& b) = a;  // ����a�ǲ����޸ĵ���������, ���ֱ�����õĻ�Ӧ����������һ��ָ�򲻿��޸ĵ�ָ�������  const int * a;(int�ǲ����޸ĵ�, int const a = 2��const int a = 2һ��) int * const a;(int * �ǲ����޸ĵ�)
		// �Գ���ָ�������
	int * bb = a;
	int c;
	int & cc = c;  // ���ñ����ʼ��, ��ʼ���Ժ�Ͳ����޸�
	int * const pr = &c;  // ��ʵcc����*pr
	

	return 0;
}
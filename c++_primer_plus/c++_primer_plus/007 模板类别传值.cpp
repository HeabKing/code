// ����: 2014-08-23 09:54:21
// template<int T>void print(int n)��void print2(int n)������һ��
#include <iostream>

using namespace std;
typedef void (defType)(int);

template<int T>		// ���������ȷ����������, �Ϳ���print<2>����һ��ֵ
void print(int n)
{
	cout << T << n << endl;
}

void print2(int n)
{
	cout << n << endl;
}

void print3(int n, int m)
{
	cout << "print3";
}

void ceshi(int n, defType f)
{
	f(n);
}

template<class fn>
void ceshi2(int n, fn f)
{
	f(n);
}

int main()
{
	print<2>(3);
	print2(4);

	// ceshi() ���ڶ������������������޶�Ϊ void (__cdecl *)(int), ��ʱtemplate<int T>void print(int n)�Ƿ�������������, ���ǿ���ͨ��T����һ��ֵ
	ceshi(5, print2);
	//ceshi(5, print3);	// error C2664: ��ceshi��: ���ܽ����� 2 �ӡ�void (__cdecl *)(int,int)��ת��Ϊ��defType (__cdecl *)��
	ceshi(6, print<7>);
		// ����print��print2�����ͻ��ǲ���ͬ��for_each()�ĵ���������������ʽ����, ��ôʵ�ֵ�??????
		// ���ǰ�ceshi����Ϊ
	ceshi2(6, print2);
	ceshi2(7, print<8>);
	//ceshi2(8, print3);	// ��ͨ��ģ�嶨���ceshi2��������ʲô���Ͷ�ͨ��, �����ڲ�������f(n)ֻʹ����һ������, ����޶��˲���������
}
#include <iostream>
using namespace std; // using ����ָ��ʹ��std���ƿռ����������ȫ�ֿ���
#include "p326���ƿռ�.cpp"

// �ں�������ʹ��using����ʱ, ����������ӵ�ȫ�����ƿռ���
using Jack::pail; // put pail into global namespace

void other();
char fetch; // global fetch
int main()
{
	cin >> pail; // read a value into Jack::fetch
	other();

// using�������ض���������ӵ�������������������, ����main()�е�using����Jill::fetch��fetch��ӵ�main()���������������
	using Jill::fetch;   // a using declaration
		// put fetch into local namesapce �����ȫ�ֱ���fetch������
// using������ͬ���ֲ�����֮ǰʹ��
	//double fetch = 1.0; // Error! Already have a local fetch // error C2086: ��double Jill::fetch��: �ض���
	cin >> fetch;		   // read a value into Jill::fetch
	cout << fetch << endl;
	cin >> ::fetch;	   // read a value into global fetch
	cout << ::fetch << endl;
// using�����ھֲ�����֮������									// ����ĵ��µ������¶���������Ƕ������ʱ��һ����, ���Ҷ��Ǻ����������г���, һ���ض���һ�������������Ϊ�и�������ʱ���ʼ����
															// ����������ͬ�����ƿռ����ͬ�����ٴ�using������ʱ��Ḳ����һ����
	//int pp = 11;
	using Jill::pp;      //  error C2874: using �������¡�Jill::pp���Ķ������
	cout << "���ƿռ��ʼ����pp = " << pp << endl;

	return 0;
}

void other()
{
	cout << pail << endl;
}
// �Լ��ܽ�
#include <iostream>
using namespace std;

template<typename T> auto add(const T a, T b) -> decltype (a + b)
{
	return a + b;
}

template<class T1, class T2> auto jian(T1 a, T2 b) ->decltype (a - b)
{
	return a - b;
}

template<class R1, typename R2> auto cheng(R1 &a, R2 &b) ->decltype (a * b)
{
	typedef decltype (a) tya;  // �����double &a�Ļ���ôtya ����double &    ???
	typedef decltype ((b)) tyb;// �����double &b�Ļ���ôtyb ����double &&   ???
	tya aa = a;
	tyb bb = b;
	cout << "aa: " << aa << endl;
	cout << "bb: " << bb << endl;
	cout << "aa + bb : " << aa + bb << endl;

	return a * b;
}

int main()
{
	int a = 6;
	double b = 2.2;

	cout << add(double(a), b) << endl;  // Ϊʲô����ֱ��дa���ܽ�����ʽ������ת��??????��Ϊ�������ܽ���ǿ�Ƶ�����ת��(p290) ������
	cout << add<double>(a, b) << endl;  // ��������������ʾ��ʵ����
	cout << jian(b, a) << endl;
	cout << jian(a, b) << endl;
	cout << cheng(a, b) << endl;

	return 0;
}
// �����嵥 11.6
#include <iostream>
#include "p384���������ʵ��ʱ�����.h"

Time operator*(double d, const Time & t);  // �÷���Ԫʵ��(int)*(class����)�ĵ��÷�ʽ

int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;
	
	cout << "planning time = ";
	planning.show();
	cout << endl;

	cout << "coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;

	total = coding + fixing;  // ֱ��ʹ�����������, ���Ϊ���ö���, �ұ�Ϊ����
	// operator notation
	cout << "coding + finxing = ";
	total.show();
	cout << endl;

	Time morefixing(3, 28);
	cout << "more fixing time = ";
	morefixing.show();
	cout << endl;
	total = morefixing.operator+(total);  // ������ĺ�������
	// function notation
	cout << "morefixing.oprator+(total) = ";
	total.show();
	cout << endl;

	total = total * 2;
	total = 2 * total;
	cout << "total = total * 2 : ";
	cout << total;  // ������Ԫ����ʵ������"<<"ʵ�����ʱ��
	cout << endl;

// t4 = t1 + t2 + t3;  =>>  t4 = t1.operator(t2 + t3);  =>>  t4 = t1.operator(t2.operator(t3));   // ��Ϊ����ֵ��һ��Time����, �����ܹ�ʵ��
							// ��Ϊ + �Ǵ������ҽ�ϵ������, �������ȷֽ������
	return 0;
}
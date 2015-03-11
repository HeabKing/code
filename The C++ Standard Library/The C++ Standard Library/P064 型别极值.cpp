// ����: 2014-08-20 08:48:20

// ʵ�ֵ�˼��: template��Ȼ��Ϊ�����ͱ�һ���Ե�׫д��һ��ͨ�õĽ������, ���ǿ�����templateΪÿ���ͱ��ṩ��ͨ�Ľӿ�. ������: �����ṩͨ�õ�template, ���ṩ��������(specialization)�汾, �������汾����min(), max(), ����������ֱ��is_specialized = false;

#include <iostream>
#include <limits>	// for numeric_limits template
#include <string>
using namespace std;
// is_specialized Ϊfalse��ʾ���ͱ�û�м�ֵ, Ϊtrue˵������������template�汾�ṩ��ֵ
int main()
{
	// use textual representation for bool
	cout << boolalpha;

	// print maximum of integral types
	cout << "max(short): "	<< numeric_limits<short>::max() << endl;
	cout << "max(int): "	<< numeric_limits<int>::max() << endl;
	cout << "max(long): "	<< numeric_limits<long>::max() << endl;
	cout << endl;

	// print maximum of floating-point types
	cout << "max(float): " << numeric_limits<float>::max() << endl;
	cout << "max(double): "<< numeric_limits<double>::max() << endl;
	cout << "max(long double): "	<< numeric_limits<long double>::max() << endl;
	cout << endl;

	// print whether char is signed
	cout << "is_signed(char): " << numeric_limits<char>::is_signed << endl;
	cout << endl;

	// print whether numeric limits for type string exit
	cout << "is_specialized(string): " << numeric_limits<string>::is_specialized << endl;
}
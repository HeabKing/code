#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;	// һ���յ�string
	cout << str << endl;
	str = "0123456789";
	cout << str << endl;
	string str1(str);	// copy���캯��, ����str��һ������Ʒ
	cout << str1 << endl;
	string str3(str, 1);	// ��str��ʼ��λ��3�Ĳ��ֵ���str3�ĳ�ֵ !!!�ڶ�������������, ��0��ʼ
	cout << str3 << endl;
	string str4(str, 4, 3);
	cout << str4 << endl;	// �ڶ�������������idx, �����������ǳ���len
	string str5("const char *(C-string)");	// ʹ��C-string��Ϊ�ַ���str5�ĳ�ֵ
	cout << str5 << endl;
	string str6("const char *(C-string)", 5);	// ��C-string��ǰ5���ַ����ַ���str6��ֵ
	cout << str6 << endl;
	string str7(5, 'C');	// ����һ���ַ���, ����5��'C'
	cout << str7 << endl;
	string str8(str.begin() + 1, str.begin() + 3);	// [beg, end)
	cout << str8 << endl;
}
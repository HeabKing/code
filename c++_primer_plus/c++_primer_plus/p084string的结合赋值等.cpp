// �����嵥 4.8
#include <iostream>
#include <string>      // make string class available
// string������Զ�������С�Ĺ���
int main()
{
	using namespace std;
	string str1 = "penguin";
	string str2, str3;

	cout << "string���ܹ�ʵ���ַ����ĸ�ֵ:(str2 = str1)\n";
	str2 = str1;
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl; 
	cout << "string���ܺϲ�(+)����ֵ(=):��str3 = str1 + str2��\n";
	str3 = str1 + str2;
	cout << str3 << endl;
	cout << "string��������ʹ��+=����:str1 += str2\n";
	str1 += str2;
	cout << str1 << endl;
	cout << "string�໹����ʵ�� str2 += \" for a day\": \n ";
	str2 += " for a day";
	cout << str2 << endl;

	return 0;
}
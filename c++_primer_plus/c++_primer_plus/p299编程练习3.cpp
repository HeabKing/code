// �����ϰ 8.8 (3)
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
auto ToUpper(string &str) ->decltype (str);
int main()
{
	string str;
	cout << "Enter the string to upper:\n";
	while (getline(cin, str) && str != "q")// getline()��ȡһ��, ����'\0'����'\n'  ��istream������Ϊ���ض���, ���������ж�����
	{	
		cout << ToUpper(str) << endl;
		cout << "Enter the string to upper:\n";
	}
	return 0;
}

auto ToUpper (string &str) ->decltype (str)
{
	char ar[100];
	int i = 0;
	while (str[i])
	{
		ar[i] = toupper(str[i]);
		i++;
	}
	ar[i] = '\0';
	str = ar;
	return str;
}
// �����嵥 6.11
#include <iostream>
enum {red, orange, yellow, green, blue, violent, indigo};

int main()
{
	using namespace std;
	cout << "Enter color code (0-6): ";
	int code;
	cin >> code;
	while (code >= red && code <= indigo) // intֵ��ö�ٱ�ǩ���бȽϵ�ʱ����Զ���ö�ٱ�������Ϊint
	{
		switch (code) // �ڽ���intֵ��ö�ٱ�ǩ���бȽϵ�ʱ����Զ���ö�ٱ�������Ϊint
		{
			case red    : cout << "red\n";   break;
			case orange : cout << "orange\n"; break;
			case yellow : cout << "yellow\n"; break;
			case green  : cout << "green\n";  break;
			case blue   : cout << "blue\n";   break;
			case violent : cout << "violent\n";break;
			case indigo : cout << "indigo\n";  break;
			//default : cout << "can't analysis.\n"; break; // while��������Ѿ����Ʋ�������default
		}
		cout << "Enter color code (0-6): ";
		cin >> code;
	}
	cout << "Bye!\n";
	
	return 0;
}
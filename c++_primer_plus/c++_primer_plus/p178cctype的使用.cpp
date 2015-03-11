// �����嵥 6.8
#include <iostream>
#include <cctype>
int main()
{
	using namespace std;
	cout << "Enter text for analysis, and type @"
		" to terminate input.\n";
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;
	while (cin.get(ch) && ch != '@')
	{
		if (isalpha(ch)) // �������ĸ�Ļ�
			chars++;
		else if (isspace(ch)) // ����ǿհ� �ַ��Ļ�
			whitespace++;
		else if (isdigit(ch)) // ����ǰ��������ֵĻ�
			digits++;
		else if (ispunct(ch)) // ����Ǳ����ŵĻ�
			punct++;
		else
			others++;
	}
	cout << chars << " letters. ";
	cout << whitespace << " whitespaces. ";
	cout << digits << " digits. ";
	cout << punct << " punctuations. ";
	cout << others << " others.\n";

	return 0;
}
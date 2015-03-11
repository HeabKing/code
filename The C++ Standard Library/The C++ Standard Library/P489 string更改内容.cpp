// Modifiers --- ��ֵ
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	char * cstring = "othello";	// C���԰������ַ�����ʾΪchar *, C++��ʾΪconst char *, ����Ϊ��֧����������ת��, C++֧��const char *��char *����ʽת��(��������)
	const string aString(cstring);	// aString[aString.length()] ���� const string֧�ַ������һ���ַ���ߵĵ�һ��λ��, ������aString��'\0'
	string s;	// s[s.length()] ERROR string��֧�ַ������һ���ַ���ߵĵ�һ��λ��

	s = aString;		// assign "othello"
	cout << s << endl;
	s = "two\nlines";	// assign a C-string
	cout << s << endl;
	s = '.';			// assign a single character
	cout << s << endl;

	s.assign(aString);	// assign "othello"(equivalent to operator=)
	cout << s << endl;
	s.assign(aString, 1, 3);	// assign "the"
	cout << s << endl;
	s.assign(aString, 2, std::string::npos);	// assign "hello"
	cout << s << endl;

	s.assign("two\nlines");		// assign a C-string (equivalent to operator=)
	cout << s << endl;
	s.assign("nico", 5);	// assign the characterr array: 'n' 'i' 'c' 'o' '\0'
	cout << s << endl;
	s.assign(5, 'x');
	cout << s << endl;		// assign five characters: 'x' 'x' 'x' 'x' 'x'
	s.assign(aString.begin(), aString.begin() + 3);
	cout << s << endl;
	s.resize(2);	// β���ַ����Ƴ�
	cout << s << endl;
}
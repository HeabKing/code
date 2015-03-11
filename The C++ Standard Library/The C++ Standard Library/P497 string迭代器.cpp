#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <locale>
using namespace std;

class bothWhiteSpaces
{
private:
	const locale & loc;		// locale ����, �ֳ�
public:
	// constructor
	// - save the locale object
	bothWhiteSpaces(const locale & l) : loc(l) {}
	// function call
	// - returns whether both characeters are whitespaces
	bool operator()(char elem1, char elem2)
	{
		return isspace(elem1, loc) && isspace(elem2, loc);
	}
};

bool nocase_compare(char c1, char c2)
{
	return toupper(c1) == toupper(c2);
}

int main()
{
			// ��string�е������ַ�ת����Сд

	// create a string
	string s("The zip code of Hondelage in Germany is 38108");
	cout << "original: " << s << endl;

	// lowercase all characters 
	transform(s.begin(), s.end(),	// source
		s.begin(),					// destination	��Դת����ŵ��ĵط�
		tolower);					// operation
	cout << "lowered: " << s << endl;

	// uppercase all characters
	transform(s.begin(), s.end(), s.begin(), toupper);
	cout << "uppered: " << s << endl;

	cout << endl << endl << endl;

	string s1("This is a string");
	string s2("STRING");

			// �ж�str1�ǲ�����str2��Ȼ����ǲ���str2��һ���Ӵ�

	// compare case insensitive
	// equal()�ĵ����߱��뱣֤�ڶ���������Ҫ�͵�һ�������һ�����Ԫ��, ����ȱȽ��ַ����Ĵ�С�Ǳ�Ҫ��
	if (s1.size() == s2.size() &&	// ensure same sizes
		equal(s1.begin(), s1.end(),	// first source string
		s2.begin(),					// second source stirng
		nocase_compare))			// comparison criterion
		cout << "the strings are equal " << endl;
	else
		cout << "the strings are not equal" << endl;

	// search case insensitive
	string::iterator pos;
	pos = search(s1.begin(), s1.end(),	// source stirng in which to serach
		s2.begin(), s2.end(),			// substring to search
		nocase_compare);				// comparison criterion
	if (pos == s1.end())
		cout << "s2 is not a substring of s1" << endl;
	else
		cout << '"' << s2 << "\" is a substirng of \""
			 << s1 << "\" (at index " << pos - s1.begin() << ")" << endl;

				// ����, ����, ɾ���ظ��ַ�
	cout << endl << endl << endl;
	// create constant string
	const string hello("Hello, how are you?");	// const��string�����һ�������'\0'

	// initialize string s with all characters of string hello
	string s3(hello.begin(), hello.end());

	// iterate through all of the characters
	string::iterator pos3;
	for (pos3 = s3.begin(); pos3 != s3.end(); ++pos3)
		cout << *pos3;
	cout << endl;

	// reverse the order of all characters inside the string
	reverse(s3.begin(), s3.end());
	cout << "reverse: " << s3 << endl;
	// sort all characters insede the string
	sort(s3.begin(), s3.end());
	cout << "ordered: " << s3 << endl;
	// remove adjacent(�ڽ���) duplicates(����)
	// - unique() reorders and returns new end	// unique ���ص� reorders �ض���, ������
	// - erase() shrinks(��С) accordingly(���, ����, ��Ӧ��)
	s3.erase(unique(s3.begin(), s3.end()), s3.end());	// ���ظ����ַ�ɾ��
	cout << "no duplicates: " << s3 << endl;
	
	string s3Temp("123456789");
	vector<char> intv(s3Temp.begin(), s3Temp.end());
	for (vector<char>::iterator i = intv.begin(); i != intv.end(); ++i)
		cout << *i;
	cout << endl;
	reverse(intv.begin(), intv.end());
	for (vector<char>::iterator i = intv.begin(); i != intv.end(); ++i)
		cout << *i;
	cout << endl << endl << endl << endl;

				// 

	string contents;
	// don't skip leading whitespaces
	cin.unsetf(ios::skipws);
	// read all characters while compressing whitespaces
	unique_copy(istream_iterator<char>(cin),	// beginning of source
				 istream_iterator<char>(),		// end of source
				 back_inserter(contents),		// destination
				 bothWhiteSpaces(cin.getloc()));	// unique_copy()��bothWhiteSpacesΪ��Ϊ׼��, ɾ�������ظ��ո�
					// criterion for removing

	// process contents
	// - here: write it to the standard output
	cout << contents;
}
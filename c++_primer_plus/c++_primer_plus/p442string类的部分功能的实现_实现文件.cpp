// �����嵥 12.5 ʵ���ļ�
#include <cstring>
#include "p442string��Ĳ��ֹ��ܵ�ʵ��.h"
using std::cin;
using std::cout;

// ��ʼ����̬��Ա
int String::num_strings = 0;
// ��̬��Ա����
// 1. ����ͨ��������þ�̬��Ա����, ʵ����, ��̬��Ա������������ʹ��thisָ��.
// 2. �����̬��Ա�������ڹ��в���������, �����ʹ����������������������������(String::HowMany())
// 3. ���ھ�̬��Ա���������ض��Ķ��������, ���ֻ��ʹ�þ�̬���ݳ�Ա
int String::HowMany()  // ��̬��Ա�����Ķ��岿�ֲ��ܼ���static
{
	return num_strings;
}
// ��Ա����
String::String(const char * s)
{
	len = std::strlen(s);
	str = new char [len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String(const String & st)
{
	num_strings++;
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str);
}

String::String()
{
	len = 4;
	//str = new char [1];  // ֮���Բ�����str = new char;����Ϊǰ������������������, ������delete [] str;�ͷ��ڴ�
	//str[0] = '\0';
	// ����delete []��ʹ��new[]��ʼ����ָ��Ϳ�ָ�����, ��˿���ֱ������д
	str = nullptr;  // 0 NULL(c���Ժ�) nullptr(c++�ؼ���) �����Ա�ʾ��ָ��
	num_strings++;
}

String::~String()
{
	--num_strings;
	delete [] str;
}

// ��������غ���
	// ��һ��string�ำ����һ��string��
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str);
	return *this;
}
	// ��һ��c�ַ�������һ��string��
String & String::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
	// �ǳ���string��Ķ�д�ַ�����
char & String::operator[](int i)
{
	return str[i];
}
	// ����string���ֻ���ַ�����
const char & String::operator[](int i) const
{
	return str[i];
}

// �����������Ԫ����
bool operator<(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

bool operator==(const String &st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}
	// string�����
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}
	// quick and dirty String input
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
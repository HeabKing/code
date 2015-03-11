#include <cstring>
#include "�о� - 005��֮dxString��.h"

using std::cout;
int dxString::num_string = 0;	// ��ʼ��ָ��������, ��ʹ���������������, ����û��ʹ�ùؼ���static
								// ��ʼ��λ�ڷ����ļ���, �������������ļ���;
// char StringBad::len = 3l;	// �Ǿ�̬���ݳ�Ա����������ⲿ����

	// ��̬��Ա��������
int dxString::HowMany()	// �����м���static, �����в��ü�
{
	return num_string;
}

dxString::dxString(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_string++;
	cout << num_string << ": \"" << str << "\" ��Ŀ������.\n";
}

dxString::dxString()
{
	len = 4;
	str = new char[len];
	std::strcpy(str, "C++");
	num_string++;
	cout << num_string << ": \"" << str << "\" ��Ŀ������.\n";
}

dxString::~dxString()
{
	cout << "\"" << str << "\" ��Ŀ��ɾ��, " << --num_string << " ��ʣ��.\n";
	delete []str;
}

std::ostream & operator<<(std::ostream & os, const dxString & st)
{
	os << st.str;
	return os;
}

std::istream & operator>>(std::istream & is, dxString & st)
{
	char temp[dxString::CINLIM];
	is.get(temp, dxString::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

// ��ȸ��ƹ��캯��
dxString::dxString(const dxString & st)
{
	num_string++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	cout << num_string << ": \"" << str << "\" ��Ŀ������.\n";
}

// ��ȸ�ֵ���������
dxString & dxString::operator=(const dxString & st)
{
	if (this == &st)	// ���⽫���󸳸�����, ��Ϊ�ڶ������¸�ֵ֮ǰ, �������ͷű���ֵ����ľ�̬���ڴ�, ����, �ͻ�ʹ�ñ����費���ڵ��ڴ�;
		return *this;
	delete [] str;		// �Ѷ���֮ǰ����ľ�̬�������ͷŵ�;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

dxString & dxString::operator=(const char * pch)
{
	delete [] str;
	len = std::strlen(pch);
	str = new char[len + 1];
	std::strcpy(str, pch);
	return *this;
}

char & dxString::operator[](int i)
{
	return str[i];
}

const char & dxString::operator[](int i) const
{
	return str[i];
}

bool operator<(const dxString & st1, const dxString & st2)
{
	return (std::strcmp(st1.str, st2.str));
}

bool operator>(const dxString & st1, const dxString & st2)
{
	return st2 < st1;
}

bool operator==(const dxString & st1, const dxString & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}
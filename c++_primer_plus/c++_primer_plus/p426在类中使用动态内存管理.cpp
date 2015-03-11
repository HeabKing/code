// �����嵥 12.1 ͷ�ļ�����
// c++������Ĭ�����ɵ������Ա����:
// 1. Ĭ�Ϲ��캯��  // û�в�����ȫ������Ĭ�ϲ����Ĺ��캯��
// 2. Ĭ����������
// 3. ���ƹ��캯��  �½�һ�����󲢽����ʼ��Ϊͬ�����ж����ʱ�򽫻��Զ����ø��ƹ��캯��, StringBad(const StringBad &);
			 // 1. ������ֵ���ݶ���  2. �������ض���  3. �����¶��󲢽����ʼ��Ϊͬ��ĳ�������ʱ��  4. ����������ӿ��ܴ�����ʱ���󱣴��м�����ʱ��
// 4. ��ֵ�����
// 5. ��ַ�����
#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad
{
private:
	char * str;  // strָ��  ����ʹ�õ���charָ�������char����, ����ζ������������Ϊ�ַ���������䴢��ռ�, �����ڹ��캯����ʹ��new��ά�ַ�������ռ�
	int len;  // str����
	static int num_strings;  // ��Ŀ����  ��̬���Ա���ص�, ���۴����˶��ٶ���, ����ֻ����һ����̬������ĸ���.
	// ����û�н��г�ʼ��, û�з����ڴ�, ������ʵ���ļ��н��еĳ�ʼ��, ������Ϊ������λ��ͷ�ļ���, ������ܽ�ͷ�ļ����������������ļ���, �����ͷ�ļ����г�ʼ��, �����ֶ����ʼ����丱��, �Ӷ���������
	// ��������Ǿ�̬���ݳ�Ա�����ͻ�ö������const, ��Ϊ���ǵ�������Ϊ�ڲ�
public:
	//====== ֻ��һ�������Ĺ��캯��������ת������ ======
	StringBad(const char * s);  // constructor
	StringBad();  // default constructor
	~StringBad();  // destructor
	StringBad(const StringBad & st);  // ��ȸ��ƹ��캯��
	StringBad & operator=(const StringBad  & st);  // ��ȸ�ֵ���������
// friend function
	friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif

// �����嵥 12.2 ʵ�ֲ���
#include <cstring>
using std::cout;

int StringBad::num_strings = 0;  // ȫ�ֱ���, ���о�̬����, �Զ�����Ϊ��
// char StringBad::len = 3l;  // �Ǿ�̬���ݳ�Ա����������ⲿ����

StringBad::StringBad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::~StringBad()
{
	cout << "\""<< str << "\" boject deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete [] str;
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
	os << st.str;
	return os;
}

// ��ȸ��ƹ��캯��
StringBad::StringBad(const StringBad & st)
{
	num_strings++;
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str);
	cout << num_strings << ": \"" << str
		<< "\" object created\n";
}
// ��ȸ�ֵ���������
StringBad & StringBad::operator=(const StringBad & st)
{
	if (this == &st)
		return *this;  // ���⽫���󸳸�����, ������������¸�ֵǰ, �ͷ��ڴ��������ɾ����������
	delete [] str;  // ����Ŀ����������������ǰ���������, ���Ժ���Ӧʹ��delete[]���ͷ���Щ����
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// �����嵥 12.3 �ͻ��ļ�
#include <iostream>
using std::cout;

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
	using std::endl;
	{
		cout << "Starting an inner block.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		puts("");

		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		puts("");

		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);  // �����￪ʼ������ 
		cout << "headline2: " << headline2 << endl;
		puts("");

		cout << "Initialize one objict to another: \n";
		StringBad sailor = sports;  // ��Ч��StringBad sailor = StringBad(sports);  // ��ʹ�õ��Ǹ��ƹ��캯�� StringBad(const StringBad &); const Ҫע�� �Զ����ɵĹ��캯����֪��Ҫ����string_num++
			// ��������ʽ���ƺ�������ʽ��ֵ���������
		cout << "sailor: " << sailor << endl;
		puts("");

		cout << "Assign one object to another: \n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		puts("");
		
		cout << "Exiting the block.\n";
	}
	cout << "End of main()\n";

	return 0;
}

void callme1(StringBad & rsb)
{
	cout << "String passed by reference:\n";
	cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)  // ÿ�����������˶���ĸ���ʱ, �������ͻ���ø��ƹ��캯��:
{                                       // 1. ������ֵ���ݶ���  2. �������ض���  3. �����¶��󲢽����ʼ��Ϊͬ��ĳ�������ʱ��  4. ����������ӿ��ܴ�����ʱ���󱣴��м�����ʱ��
	cout << "String passed by value: \n";
	cout << "   \"" << sb << "\"\n";
}
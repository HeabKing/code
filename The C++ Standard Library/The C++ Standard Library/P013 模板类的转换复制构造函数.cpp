#include  <iostream>
using namespace std;
template <class T>
class MyClass
{
public:
	// copy constructor with implicit type conversion
	// - dose not hide implicit copy constructor
	// ��ʽ����ת�����ƹ��캯��
	// - ��������ʽ���ƹ��캯��
	template <class U>
	MyClass(const MyClass<U> & x){}
	MyClass(){}

	// �����ͱ����ʾ��ʼ��
	// ���ò���������, ��ȷ��constructor�����﷨ int i = int(); �����ͱ�ᱻ��ʼ��Ϊ0
	void f() { T x = T(); }		// T x = T(); ������Ա�֤��template���������, �κ��ͱ���һ��ȷ�еĳ�ʼֵ;
};

int main()
{
	MyClass<double> xd;
	MyClass<double> xd2(xd);	// ���� built-in ���ƹ��캯��
		// ����xd2��xd�ͱ���ȫһ��, ���������ڽ��ĸ��ƹ��캯����ʼ��

	MyClass<int> xi(xd);		// ����ģ�幹�캯��
		// xi��xd���ͱ�ͬ, ������ʹ��template���캯�����г�ʼ��
}
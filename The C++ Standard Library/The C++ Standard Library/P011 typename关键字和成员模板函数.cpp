#include <iostream>
using namespace std;

class Q
{
public: 
	typedef int SubType;
};

template <class TT>
class MyClass
{
public:
	typename TT::SubType * ptr;	// ���� typename ָ�� SubType �� class TT �е�һ���ͱ�, ���û��typename, SubType�ᱻ����һ�� static ��Ա, ����, T::SubType * ptr����һ���˻�;
		// �����κ�һ�������滻T���ͱ�, ���ڲ������ṩһ�� inner type �ڲ��ͱ� SubType �Ķ���
		// C++ ��һ������ǳ���typename����֮��, template�ڵ��κα�ʶ���Ŷ�����Ϊһ��ֵ����һ���ͱ�

	template <class T/* = int*/>	// error C4519: ����������ģ����ʹ��Ĭ��ģ�����
	/*virtual*/ void f(T)			// error C2898: ��void MyClass::f(T)��: ��Ա����ģ�岻���������
		// ��Աģ�庯��������virtual, Ҳ������ȱʡ����
	
	{
		cout << "MyClass f()" << endl;
	}
};

// ��Աģ�庯��ͨ������Ϊtemplate classes �еĳ�Ա�ṩ�Զ��ͱ�ת��
template <typename T>
class YourClass
{
public:
	YourClass(T t) { Tvalue = t; }
private:
	T Tvalue;
public:
	void assign(YourClass<T> & yourclass)	// ����ʹ�õĲ����ͱ���һ��ģ�����YourClass<T>, ʹ��youclass�ɹ�����ʾΪ "�ͱ�T��YourClass���һ�����������" (��Ϊ��Աyourclass�ṩ���ͱ�ת��)
		// "���뾫ȷ�Ǻ�", ��ʹYourClass<double>��YourClass<int>֮����Խ����Զ�����ת��
	{
		Tvalue = yourclass.Tvalue;
		cout << Tvalue << endl;
	}
	void assign(const int & i)
	{
		cout << i << endl;
	}
	template <class TT>	// �ſ�"���뾫ȷ�Ǻ�"�ķ���
	void assign2(const YourClass<TT> & yourclass)
	{
		//Tvalue = yourclass.Tvalue;	// error C2248: ��YourClass<T>::Tvalue��: �޷����� private ��Ա(�ڡ�YourClass<T>����������)
		// ��������������YourClass<TT>���ܸ�YourClass<T>(������YourClass<int>���з���YourClass<double>���е�˽�б���)��������ͬһ����, ����������yourclass���п��ܲ��ܷ���˽�б�����, ��������͸�ʹ�ø�getValue()֮��Ĺ��к���
		Tvalue = yourclass.getValue();
		cout << Tvalue << endl;
	}
public:
	T getValue() const { return Tvalue; }
};

int main()
{
	//MyClass<int> myclass;		// error C2039: ��SubType��: ���ǡ�`global namespace'���ĳ�Ա
	MyClass<Q> myclass;
	myclass.f<int>(0);

	YourClass<int> intYourClass(1);
	intYourClass.assign(YourClass<int>(2));	// ����ʹ�õ���void assign(YourClass<T> & yourclass); ����ʹ������Ĳ���û�м���const, ����ȴ�ܳɹ�������ʱ�����ò�������, ����Ϊ�������Ե��??? // ����Ϊ2��һ������ֵ, ��������ת�������һ����ʱ����
	intYourClass.assign(int(3.00));			// ����ʹ�õ���void assign(const int & i), �����constȥ���������, ��Ϊ�û����������ɵ���ʱ��������������const���õ�ǰ����??? // ����3.00��һ������ֵ, ����int����ת����Ϊ3, ����һ������ֵ, const���÷���ֵ������const���òŻ�������ʱ����Ȼ��������ʱ����
	intYourClass.assign(4.22);	// const�����β���һ������: ����ʵ�ε����������ò������Ͳ�ƥ��, ���ǿ��Ա�ת������������, ���򽫻ᴴ��һ����ȷ���͵���ʱ����, ʹ��ת�����ʵ��ֵ����ʼ����, Ȼ�� ����һ��ָ�����ʱ����������.

	// 4. �����������Գ�ʼ��Ϊ�κ���ֵ, ���Ƿ���ֵֻ����const��������ʼ��, ��Ϊ����ֵ���г�ʼ����ʱ�򽫻������ʱ����, ������ʹ��������Ϊ�����������������������ı���������ֵ��������ʱ������ֵ, �����������ܷ������׷��ֵĴ���, ���Ըɴ��ֹ�˲�����ʱ����, ���������c++�ҵ���const����, �����Ͳ������޸�ֵ.
//    const�����β���һ������: ����ʵ�ε����������ò������Ͳ�ƥ��, ���ǿ��Ա�ת������������, ���򽫻ᴴ��һ����ȷ���͵���ʱ����, ʹ��ת�����ʵ��ֵ����ʼ����, Ȼ�� ����һ��ָ�����ʱ����������.
//    ��ֵ: ����, ����Ԫ��, �ṹ��Ա, ���úͽ�����õ�ָ��, ����ֵ�������泣��(���������������ַ�������, ���������ַ��ʾ)�Ͱ�������ı��ʽ
//    ��ֵ: ����ͨ����ַ���ʵ�ֵ

	//intYourClass.assign(YourClass<double>(5.0));	
		// ��ʹ�����ͱ�֮�����ʵ���Զ�ת��, ���ﻹ��Ҫ��"���뾫ȷ�Ǻ�"
		// �ſ�"���뾫ȷ�Ǻ�"�ķ���: �ṩ��ͬtemplate�ͱ�(ֻҪ�ͱ�ɱ���ֵ);
	intYourClass.assign2(YourClass<double>(5.0));	
}
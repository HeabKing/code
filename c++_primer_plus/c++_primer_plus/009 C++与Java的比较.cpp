// ����: 2014-09-13 13:16:21
// # 1 �����ַ� + ����		C++�в�����, java��Ĭ�Ͻ�"string"ת��ΪString��, Ȼ��String + int��String, int + String����String
// # 2 ���캯�����ù��캯�� C++�в�����	 java��֧��, ����ֻ�ܵ���һ��this(args)
// # 3 ����(new ����)��ʱ�����ķ������õĿ�����	
	// Java�п���ʹ�� new Obj.mem...
	// C++��ʹ�� new Obj->mem...�ᱨ��˵->ǰȱ��";", Ӧ��ʹ��(new Obj->mem), ���Ǵ�ʱҪע��, ִ�����ڴ��й¶��
// # 4 �����������ݵĳ�ʼ��

#include <iostream>
#include <string>
using namespace std;
class ClassType
{
public:
	int i;
public:
	ClassType(int i) 
	{ 
		this->i = i; 
	}
	ClassType() { 
		//(*this)(9999);	// C++��֧�ֹ��캯��������һ�����캯��
		*this = ClassType(999);	// �����滻java�еĵ��ù��캯���ķ�������
		cout << "\nmorengouzaohanshubeidiaoyong\n";
		cout << ClassType(333).i; 
	}
};

// # 4 �����������ݵĳ�ʼ��
class T
{
public:
	int i;
	//int ii = 1;	// ������, java������
	//static int iii = 111;	// ������, java������
	const static int iiii = 1111;	// ����
};

int main()
{
	// # 1
	/*int t = int();
	string str = "string";
	cout << str + t; */

	ClassType c;
	cout << c.i;

	// # 3 ����(new ����)��ʱ�����ķ������õĿ�����	
	cout << "\n\n#3\n";
	cout << (new ClassType(20140915))->i << endl;

	// # 4 �����������ݵĳ�ʼ��
	cout << "\n# 4 �����������ݵĳ�ʼ��\n";
	T t;
	//cout << t.i << endl;// warning , rutime error ���ܳ�ʼ��
	cout << t.iiii << endl;
	cout << T::iiii << endl;
}
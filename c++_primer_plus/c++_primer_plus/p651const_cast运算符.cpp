// ����: 2013 12 16 18
// ��ϰ: 2014 08 15 14 # 1

// �ĸ�����ת�������: # 1
//		dynamic_cast, ʹ���ܹ����۲�νṹ�н�����������ת��(����is-a��ϵ, ����������ת���ǰ�ȫ��), ������������ת��    �� base * pfather =  dynamic_cast<base *>(ָ������������ָ��), �������ʵ��ת��, ��nullptr����pfather    ������ܵĻ�, �������ʹ��һ��ָ������ָ��������һ��ָ���������ָ��, ����, ��������ؿ�ָ�� !!!ע��, dynamic_castֻʹ��������麯���Ķ�̬������
//		const_cast, ֻ��ɾ��const, ���Ͳ��ܸı� ע��: ���ı����ָ�����͵�ʱ��, ֻ��ָ���ֵ�Ƿ�const����ʵ�ָı�
//		static_cast, static_cast<type-name>(expression) ֻ�е�expression���������Ϳɱ���ʽת��Ϊtype-name !����! type-name���Ա���ʽת��Ϊexpression�������͵�ʱ��, ת���źϷ�
//		reinterpret_cast

#include <iostream>
using std::cout;
using std::endl;
void change(const int * pt, int n);

class A
{
public:
	int a;
	A(int _a): a(_a){}
	virtual ~A() {};	// dynamic_cast<typename>(expression)Ҫ��expression����Ϊ��̬������, ���Bû�д�A�м̳�һ���麯��, ��ô���Ͳ��Ƕ�̬������, ����Ϊʲô����Ϊ�����Ƕ�̬�������� ??? 
};

class B : public A
{
public:
	int b;
	B(int _b, int _a = 12) : A(_a), b(_b){}
};

class C
{
public:
	int c;
};

int main()
{
	int pop1 = 38383;
	const int pop2 = 2000;

	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;

	cout << endl << endl;

	int a = static_cast<int>(3.25);		// # 1 ������static_cast�����滻ƽʱʹ�õ�����ת�� # 1
	//int b = static_cast<int>(&a);
	cout << a << endl;

	cout << endl << endl;

	A aa(1);
	cout << aa.a << endl;
	B bb(2);
	cout << bb.b << endl;
	A aaa = bb;	// ��������ֱ�Ӹ�ֵ������(������A�Զ����ɵĸ��ƹ��캯��)
	cout << aaa.a << endl;	// aaa��aֵ����Ϊ12
	//cout << aaa.b << endl;	// ����aaa������ΪA, ����û��aaa.b����
	A * pa = &bb;	// ��bb�ĵ�ַ��ֵ��pa, �ⲻͬ���ϱߵ�aaa, ��Ϊ�ϱߵ�aaa��ʵ���Ѿ���A������, ���������pa��Ȼ��������(A *)����, ���Ǹ���������(B *)��ָ��, ���Լ�ʹ������ʹ��pa->b���ǿ���ͨ��dynamic_castʵ�ֻ�ԭΪB *
	cout << pa->a << endl;
	//cout << pa->b << endl;	// b��������
	B * pb = dynamic_cast<B *>(pa);	// ����������ȫ����ʹ��B * pb = (B *)(pa)��, ����B * pb = (C *)(pa)������Ҳ�ᱨ��	// �����ת���ǰ�ȫ��, ��Ϊpa��Ȼ��(A *)����, ������ָ�����(B *)���͵Ķ���, ����ʹ��B * pb = (B *)(pa)Ҳ��, ��Ȼ�������ڲ���ȫ��ʱ�򷵻�nullptr
	cout << pb->b << endl;		// b������

	B * bbbbb = (B *)&aa;	// ���������ָ��ָ�����
	cout << "....." << bbbbb->a << bbbbb->b << endl;	// ����bbbbb->b������-858993460 ���ǲ���ȫ��
	B * bbbbbb = dynamic_cast<B *>(&aa);				// ���������ǲ���ȫ��, ���Է��ص���nullptr, ��ͱ��ϱߵİ�ȫ���� 
	if (bbbbbb)
		cout << "....." << bbbbbb->a << bbbbbb->b << endl;

	return 0;
}

void change(const int * pt, int n)
{
	int * pc;
	pc = const_cast<int *>(pt);  // ����ָ������ݲ���const���Ͳ���
	*pc += n;
}
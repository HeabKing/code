// ������ 2013.12.13.19
// ��ϰ:  2014.08.14.21  # 1

// �쳣���ݶ���ĺô�: # 1
	// 1.	����ʹ�ò�ͬ���쳣���������ֲ�ͬ�ĺ����ڲ�ͬ��������������쳣;
	// 2.	�������Я����Ϣ, ����Ա���Ը�����Щ��Ϣ��ȷ�������쳣��ԭ��, ͬʱ, catch����Ը�����Щ�쳣��������ȡʲô���Ĵ�ʩ;

// �����嵥 15.10 + 15.11
#include <iostream>
class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	void mesg();
};

inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): "
		<< "invalid arguments: a = -b\n";
}

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	const char * mesg();
};

inline const char * bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}

#include <cmath>
double hmean(double a, double b);
double gmean(double a, double b);
int main(void)
{
	using std::cout;
	using std::endl;
	using std::cin;

	double x, y, z;

	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set to numbers <q to qiut>: ";
		}
		catch (bad_hmean & bg)	// ����ʹ�õ�������, ע������Ĵ������� # 1
								// �����쳣��ʱ��, ���������Ǵ���һ����ʱ����, ��ʹ�쳣�淶��catch����ָ���������� # 1
								// �����bg�Ƕ�hmean()�д������Զ�����(throw bad_hmean(a, b);)��һ����ʱ����������, ��hmean()����ִ������Ժ�, throw�������Զ���������������, Ȼ���������õ��Ǹ���, ���Բ�����ִ��� # 1
								// ��������Ϊʲô������������, ������������һ������, ֱ��ʹ�ô�ֵ���͵���, �������ñ��ⴴ��������Ч���Ѿ���������.  ԭ����: ���û�������һ������, �������ÿ���ָ�������� # 1
								// ���Դ������������������õĴ������, ��catch�����ʹ�û������ʱ, ���������е����������, �����������Խ��ᱻ��ȥ, ��˽�ʹ���鷽���Ļ��۰汾 # 1
		{
			bg.mesg();
			cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean & hg)
		{
			cout << hg.mesg();
			cout << "Value used: " << hg.v1 << ", " << hg.v2 << endl;
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}
	cout << "Bye!\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
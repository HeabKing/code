// ����		2013.12.13.19
// ��ϰ		2014.08.14.22  # 1

// �����嵥 15.10 �� 15.12 # 1
#include <iostream>
class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	inline void mesg();
};

void bad_hmean::mesg()
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
	inline const char * mesg();
};

const char * bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}

#include <cmath>
#include <string>

class demo
{
private:
	std::string word;
public:
	demo (const std::string & str)
	{
		word = str;
		std::cout << "demo " << word << " created\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " destroyed\n";
	}
	void show() const
	{
		std::cout << "demo " << word << " lives!\n";
	}
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "Enter tow numbers: ";
		while (cin >> x >> y)
		{
			try
			{
				z = means(x, y);
				cout << "The mean mean of " << x << " and " << y
					<< " is " << z << endl;
				cout << "Enter next pair: ";
			}	// ���һ��û������, �ڶ�����main()�����ֻ�ܵ���abort()��, ����������Ϊ���Ըı� # 1
			catch (bad_hmean & bg)  // bgָ����Ǹ��������Ǳ���, ��Ϊ����ִ��������ڵ����б�����������, ����ָ�����һ�������Ǻõ�, ���ﻹʹ�����õ�ԭ����: �������ÿ���Ӧ�õ�������
			{
				bg.mesg();
				cout << "Try again.\n";
				continue;
			}
			catch (bad_gmean & hg)
			{
				cout << hg.mesg();
				cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
				cout << "Sorry, you don't get to play anymore.\n";
				break;
			}
		}
		d1.show();
	}
	cout << "Bye.\n";
	cin.get();
	cin.get();
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

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);  // �����쳣��ִֻ��catch������
	}	// try���׳����쳣ֱ�ӵ������� # 1
	catch (bad_hmean & bg)
	{
		bg.mesg();
		std::cout << "Caught in means()\n";
		throw;  // ����means()��ִֹ��, �����쳣���ݸ����ĵ��ú���main()���� �쳣���׳�����������Զ�����(d2��)�ͷ�
			// ���ע����, ��ô�������ִ�����쳣���쳣��Ϣ����, Ȼ��ִ���±ߵ�d2.show(), Ȼ��return�����ú���

	}	// ����������ﻹû��ƥ����쳣(����bad_gmean), ֱ�������������ú���main() # 1
	d2.show();
	return (hm + gm + am) / 3.0;
}
#include <iostream>
#include "p343 ��ʼ��.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
	company = co;
	
	if (n < 0)
	{
		std::cout << "��Ʊ����������Ϊ����, �Զ���" << company << "��˾�Ĺ�Ʊ�����ó�0!\n";
		shares = 0;
	}
	else
		shares = n;

	share_val = pr;
	set_tot();
}


void Stock::buy(long num, double price)
{
	if (num < 0)
		std::cout << "���Ĺ������Ǹ���, ����ʧ��!\n";
	else
	{
		shares	   += num;
		share_val	= price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
		std::cout << "�����۳�����Ϊ����, ����ʧ��!\n";
	else if (num > shares)
		std::cout << "���ĳ�������������Ҫ�۳�������, ����ʧ��!\n";
	else
	{
		shares	   -= num;
		share_val	= price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show(void)
{
	using std::cout;
	using std::ios_base;

		// ����ʽ���ó� #.###
	ios_base::fmtflags	orig		= cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize		prec		= cout.precision(3);

	cout << "��˾: " << company
		 << "	����: " << shares << std::endl;
	cout << "	�ɼ�: $" << share_val;

		// ����ʽ���ó� #.##
	cout.precision(2);
	cout << "	�ܼ�ֵ: $" << total_val << std::endl;
			
		// �������ʽ��ԭ
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
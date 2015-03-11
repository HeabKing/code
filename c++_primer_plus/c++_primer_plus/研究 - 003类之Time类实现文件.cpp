#include <iostream>
#include "�о� - 003��֮Time��.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours	= h;
	minutes	= m;
}

void Time::AddHr(int h)
{
	hours	+= h;
}

void Time::AddMin(int m)
{
		// ע������ʵ��ʱ���߼��ķ�ʽ

	minutes	+= m;
	hours	+= minutes / 60;
	minutes %= 60;
}

void Time::Reset(int h, int m)
{
	hours	= h;
	minutes = m;
}

Time Time::operator+(const Time & t) const
{
	Time	Sum;	// ��ĳ�Ա����������ʹ�������;
	Sum.minutes	= minutes	+ t.minutes;  
	Sum.hours	= Sum.minutes / 60 + hours + t.hours;
	Sum.minutes	%= 60;
	return Sum;
}

Time Time::operator*(const double db) const
{
	Time	result;
	long	totalminutes	= (long)(hours * db * 60 + minutes * db);
	result.hours	= totalminutes / 60;
	result.minutes	= totalminutes % 60;
	return	result;
}

void Time::Show() const
{
	std::cout << hours << " hours, " << minutes << " minutes.\n";
}

std::ostream & operator << (std::ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes.\n";
	return os;
}
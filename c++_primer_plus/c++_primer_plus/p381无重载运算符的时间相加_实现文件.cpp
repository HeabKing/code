// �����嵥 11.2 ʵ���ļ�
#include <iostream>
#include "p381�������������ʱ�����.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::Sum(const Time & t) const  // ��������������Ϊ���ô�ֵ���ӿ�, ���Ƿ���ֵ����������, ��Ϊ�����ľֲ��������ں���������ʱ����ʧ����Ӧ�ô���ֵ����������
{
	Time sum;
	sum.minutes = this->minutes + t.minutes;  // this-> ��ȫ����ʡ��
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

void Time::show() const
{
	std::cout << hours << " hours, " << minutes << " minutes";
}
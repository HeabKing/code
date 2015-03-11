// �����嵥 11.4 ͷ�ļ�
#include <ostream>
#ifndef MYTIME_H_
#define MYTIME_H_

class Time
{
private:
	int h;
	int m;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time & t) const;  // ������+�����ҼӲ��ӿո�����
	Time operator*(double)const;
	void show() const;
	friend void operator<<(std::ostream &, Time &);
		// ��Ԫ�������Ա����������: ��Ա�������ඨ���һ����, ͨ���ض��Ķ���������, ��Ա����������ʽ�ķ��ʵ��ö���ĳ�Ա, ������Ҫʹ�ó�Ա�����
							   // ��Ԫ�������������ɲ���, ��˱���Ϊֱ�Ӻ�������, ��Ԫ����������ʽ�������Ա, �����뽫��Ա�����������Ϊ�������ݵĶ���
};

#endif
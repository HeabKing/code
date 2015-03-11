// ʹ�û��෽��ʹ�������������    (��������ʾ���޶����������ʺ�����Ԫ����, ��Ϊ��Ԫ������������)
// ʹ�û��������ʹ��ǿ������ת��
// ʹ�û�����Ԫ��������ͨ����ʾ��ת��Ϊ������������ȷ�ĺ���
#include "p544Has-a��ϵ֮˽�м̳�_ͷ�ļ�.h"
using namespace std;

// public ����
double Student::Average() const
{
	if (ArrayDb::size() > 0)  // ��Ա����ͨ������������������Ӷ����public����
		return ArrayDb::sum()/ArrayDb::size();
	else
		return 0;
}

const string & Student::Name() const
{// ����������һ������, ������ָ�����ڵ��ø÷��������Student�����еļ̳ж�����string����
	return (const string &)*this;  // �����Ӷ�����ʹ��ǿ������ת����������
}

double & Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}

double Student::operator[](int i) const  // const ���͵ķ��ص�ʱ���������const�Ͳ�Ҫ����ֱ�Ӵ�����ʱ����������
{
	return ArrayDb::operator[](i);
}

// private ����
ostream & Student::arr_out(ostream & os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << " empty array ";
	return os;
}

// friend

// ʹ��string�汾��operator>>()
istream & operator>>(istream & is, Student & stu)
{
	is >> (string &)stu;
	return is;
}

// ʹ��string friend getline(ostream &, const string &)
istream & getline(istream & is, Student & stu)
{
	getline(is, (string &)stu);
	return is;
}

// ʹ��string�汾��operator<<
ostream & operator<<(ostream & os, const Student & stu)
{
	os << "Scores for " << (const string &)stu << ":\n";  // ͨ������ת�������û������Ԫ����
	stu.arr_out(os);  // ʹ��˽�к���
	return os;
}
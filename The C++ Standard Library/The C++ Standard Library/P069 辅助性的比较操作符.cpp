// ����: 2014-08-20 09:39:44
// �ĸ�template functions, �ֱ����� != > <= >= �ĸ��Ƚϲ�����, ���Ƕ������� == �� < ��ɵ�
// �ĸ���������std::rel_ops::���ƿռ��ж����template, ֻ�趨��<��== �������Ϳ���ʹ��������, ����using namespace std::rel_ops, �����ĸ��Ƚϲ��������Զ�����˶���
#include <utility>	// for inline bool std::rel_ops::operator!= (const T & x, const T & y);
#include <iostream>
class A
{
private:
	int n;
public: 
	A(int nn) { n = nn; }
	bool operator== (const A & a) const { return n == a.n; }
	bool operator< (const A & a) const { return n < a.n; }
};

int main()
{
	A a(1);
	A b(2);

	std::cout << "a > b ? : " << std::rel_ops::operator>(a, b) << std::endl;
	using namespace std::rel_ops;
	std::cout << "a != c ? : " << (a != b) << std::endl;
}
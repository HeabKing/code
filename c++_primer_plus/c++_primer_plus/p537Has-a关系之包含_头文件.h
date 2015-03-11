#ifndef �����嵥14_1
#define �����嵥14_1

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;  // ������һ������
	ArrayDb scores;    // ��������һ������
	// �ɼ������˽�к���
	std::ostream & arr_out(std::ostream & os)const;
public:     // ��ʽ�����˰�������Ĺ��캯��
	Student():name("Null Student"), scores() {}
	explicit Student(const std::string & s) : name(s), scores() {}  // ��������ʽ����   һ�������Ĺ��캯��ʵ�ֲ����������͵�����ת�� ���ʡ����explicit, ��ô������Student d("Homer", 10); ��ʱ�򴴽���һ������, �����scores����Ϊ10, ���ǵ���d[0]��д��d = 5;��ʱ��, �����Student(5), ��5ת����һ����ʱ��Student����, Ȼ����ʱ����ֵ��d, ʹ��d��scores����Ϊ5, stringΪNully
	explicit Student(int n) : name("Nully"), scores(n) {}  // ��������ʽ����
	Student(const std::string & s, int n) : name(s), scores(n) {}
	Student(const std::string & s, const ArrayDb & a) : name(s), scores(a) {}
	Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {}
	~Student() {}
	double Average() const;
	const std::string & Name() const;
	double & operator[] (int n);
	double operator[] (int n) const;
// ��Ԫ����
	// ����
	friend std::istream & operator>>(std::istream & is, Student & stu);
	friend std::istream & getline(std::istream & is, Student & stu);
	// ���
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif
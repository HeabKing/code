// ˽�м̳кͰ���������:
//     1. �����汾�ṩ��������ʾ�����Ķ����Ա, ˽�м̳��ṩ�����������Ƶ���������Ա.
//     2. ��Ա��ʼ���б��ʱ�����ʹ�ö�������ʾ���ù��캯��, ��˽�м̳�ʹ��������::����
// ʹ�ð�������˽�м̳�:
//	   ͨ��Ӧʹ�ð���������has-a��ϵ, �����Ҫ�������ԭ����ı�����Ա����Ҫ���¶����麯��, ��ʹ��˽�м̳�
#ifndef �����嵥14_4
#define �����嵥14_4
#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	//std::string name;  // ������һ������
	//ArrayDb scores;    // ��������һ������
	// �ɼ������˽�к���
	std::ostream & arr_out(std::ostream & os)const;
public:     // ��ʽ�����˰�������Ĺ��캯��
	Student(): std::string("Null Student"), ArrayDb() {}
	explicit Student(const std::string & s) : std::string(s), ArrayDb() {}  // ��������ʽ����   һ�������Ĺ��캯��ʵ�ֲ����������͵�����ת�� ���ʡ����explicit, ��ô������Student d("Homer", 10); ��ʱ�򴴽���һ������, �����scores����Ϊ10, ���ǵ���d[0]��д��d = 5;��ʱ��, �����Student(5), ��5ת����һ����ʱ��Student����, Ȼ����ʱ����ֵ��d, ʹ��d��scores����Ϊ5, stringΪNully
	explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}  // ��������ʽ����
	Student(const std::string & s, int n) : std::string(s), ArrayDb(n) {}
	Student(const std::string & s, const ArrayDb & a) : std::string(s), ArrayDb(a) {}
	Student(const char * str, const double * pd, int n) : std::string(str), ArrayDb(pd, n) {}
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
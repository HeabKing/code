// ����: 2014-08-19 20:44:41
#ifndef STUDENT_H

#include <string>
#include <vector>
#include <map>

#define NAMESPACE_DATA_BEGIN	namespace data{
#define NAMESPACE_END			};

NAMESPACE_DATA_BEGIN	// �޶����ƿռ�data, ���Ǵ�������
using std::string;
class StuBaseInfo		// ѧ��������Ϣ��
{
private:
	int		number;		// ѧ��
	int		dormNum;	// �����
	string	name;		// ����
	string	sex;		// �ͱ�
	string	tel;		// �绰
	string	label;		// ��ǩ

public:
	StuBaseInfo() {}
	virtual ~StuBaseInfo() {}

	// ��ȡ˽������
	const int number()  const	{ return number; }
	const int dormNum() const	{ return dormNum; }
	const string &	name()	const	{ return name; }
	const string &	sex()	const	{ return sex; }
	const string &	tel()	const	{ return tel; }
	const string &	label() const	{ return label; }
	// ����˽������
	void setNumber(const int n)	{ number = n; }
	void setDormNum(const int n){ dormNum = n; }
	void setName(const string & s)	{ name = s; }
	void setSex(const string & s)	{ sex = s; }
	void setTel(const string & s)	{ tel = s; }
	void setLabel(const string & s)	{ label = s; }
};

class Stu	// ���ѧ���ɼ�
{
private:
	typedef struct
	{
		int ordinaryGrade;	// ƽʱ�ɼ�
		int examGrade;		// ����ɼ�
		double totalGrade;	// �ۺϳɼ�
	} GradeDataType;
	typedef std::map<string, GradeDataType> GradeType;
private:
	StuBaseInfo baseData;	// ѧ����������
	std::pair<string, GradeDataType> tempGrade;	// ��ʱ��
	GradeType	grades;		// �洢�ɼ�����

public:
	Stu() {}
	virtual ~Stu() {}

	// ��ȡ
	const StuBaseInfo & baseData() const { return baseData; }
	const GradeType & grades() const { return grades; }
	// ����

};

NAMESPACE_END	// namespace data

#endif
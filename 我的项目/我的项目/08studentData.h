// ����: 2014-08-21 20:20:53
#ifndef	STUDENTDATA_H
#define STUDENTDATA_H
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>
class StuBaseInfo
{
	typedef std::string string;
public:
	typedef std::vector<std::pair<std::string, std::string> > baseInfoVector;
private:
	baseInfoVector baseInfo;

public:
	StuBaseInfo() {}
	virtual ~StuBaseInfo() {}

	string & operator[](const string & key);	// ʹ��baseInfo["name"] = "daxiong", ��������ֶ�"name"�⽫�Ǹ���, ���������
	const string & operator[](const string & key) const;
	auto begin()->decltype(baseInfo.begin()) { return baseInfo.begin(); }
	//decltype(baseInfo.begin()) end() { return baseInfo.end(); }	// error C2228: ��.begin������߱�������/�ṹ/���� ?????
	auto end()->decltype(baseInfo.end()) { return baseInfo.end(); }
	auto cbegin()->decltype(baseInfo.cbegin()) { return baseInfo.cbegin(); }
	auto cend()->decltype(baseInfo.cend()) { return baseInfo.cend(); }
};

class StuGraInfo
{
private:
	typedef std::string string;
public:
	typedef std::vector<std::pair<string, std::vector<int>>> graInfoType;	// int[3]: (0)ƽʱ�ɼ� (1)����ɼ� (2)�ۺϳɼ�(3:7)
private:
	graInfoType graInfo;
	graInfoType::iterator currentCourse;	// ָ��ǰ�γ�
		// ��ʼ��ΪֵΪnull, ���Զ�����Ϊ������ӵĿγ�
		// ordinaryGra(), examGra(), totalGra()�ֱ𷵻ص�ǰ�γ̵���Ӧ�ɼ�

	void updateTotalGra();

public:
#pragma message("����ĳ�ʼ��û������� StuGraInfo() { currentCourse = null; }")//StuGraInfo() { currentCourse = null; }
	~StuGraInfo() {}

	StuGraInfo & operator[](const string & key);	// Stu["��ѧ"]ָ����ǰ�����γ�����ѧ, ����γ̲����ڽ�����(�ɼ�����-1)	
	const StuGraInfo & operator[](const string & key) const;
	// ���ض�����Ϊ��ʵ�� Stu["��ѧ"].ordinaryGra()�����ĵ���
	int & ordinaryGra()				{ updateTotalGra(); return (currentCourse->second)[0]; }
	int & examGra()					{ updateTotalGra(); return (currentCourse->second)[1]; }
	const int & ordinaryGra() const	{ return (currentCourse->second)[0]; }
	const int & examGra() const		{ return (currentCourse->second)[1]; }
	const int & totalGra() const	{  return (currentCourse->second)[1]; } // �ۺϳɼ��������, "ֻ��"
	// Ϊ��ʵ��������ֵ stu["��ѧ"].ordinaryGra(100).examGra(98);
	StuGraInfo & ordinaryGra(int n) { (currentCourse->second)[0] = n; return *this; }
	StuGraInfo & examGra(int n)		{ (currentCourse->second)[1] = n; return *this; }

	auto begin()->decltype(graInfo.begin()) { return graInfo.begin(); }
	auto end()->decltype(graInfo.end())		{ return graInfo.end(); }
};


#endif
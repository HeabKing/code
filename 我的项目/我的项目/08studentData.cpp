//	����: 2014-08-28 07:36:40
#include "08studentData.h"

std::string & StuBaseInfo::operator[](const string & key)
{
	// ����Ѿ�����, ����ʵֵ����
	for (auto pos = baseInfo.begin(); pos != baseInfo.end(); ++pos)
		if (pos->first == key)
			return pos->second;
	// ���������, �����ֶ�, Ĭ�������µ�ʵֵΪnull
	baseInfo.push_back(std::make_pair(key, "null"));
	return baseInfo.back().second;
}

const std::string & StuBaseInfo::operator[](const string & key) const
{
	// Ѱ���Ƿ����
	for (auto pos = baseInfo.begin(); pos != baseInfo.end(); ++pos)
		if (pos->first == key)
			return pos->second;
	throw std::invalid_argument("������keyֵΪ" + key + "�Ļ�����Ϣ!");
}

void StuGraInfo::updateTotalGra()
{
	auto t =	(currentCourse->second)[0] * 0.3 + 
		(currentCourse->second)[1] * 0.7;
	(currentCourse->second)[2] = t > 0 ? int(t + 0.5) : int(t - 0.5);	// 78.2 => 78    78.6 => 79		-1.3 => -1
}

StuGraInfo & StuGraInfo::operator[](const string & key)	
{
	// ����Ѿ�����, ����ǰ�����γ̸ĳ�keyָ��Ŀγ�
	for (auto pos = graInfo.begin(); pos != graInfo.end(); ++pos)
	{
		if (pos->first == key)
		{
			currentCourse = pos;
			return *this;
		}
	}
	// ���������, ��ô���ӿγ�, Ĭ�ϳɼ�����-1
	graInfo.push_back(std::make_pair(key, std::vector<int>(3, -1)));	// vector<int>(3, -1) ����һ����СΪ3��vector, ÿ������-1
	currentCourse = graInfo.end() - 1;
	return *this;
}

const StuGraInfo & StuGraInfo::operator[](const string & key) const
{
	for (auto pos = graInfo.cbegin(); pos != graInfo.cend(); ++pos)
		if (pos->first == key)
			return *this;
}
#include "p533�����ϰ3_ͷ�ļ�.h"
#include <cstring>
using namespace std;

// ============= ABC ==================
ABC::ABC(const char * l, int ra)
{
	label = new char[strlen(l) + 1];
	std::strcpy(label, l);
	rating = ra;
}

ABC::~ABC()
{
	delete [] label;
}

ABC & ABC::operator=(const ABC & abc)
{
	if (&abc == this)
		return *this;

	delete [] label;
	label = new char[strlen(abc.label) + 1];
	strcpy(label, abc.label);
	rating = abc.rating;
	return *this;
}

ABC::ABC(const ABC & abc)
{
	label = new char[strlen(abc.label) + 1];
	strcpy(label, abc.label);
	rating = abc.rating;
}

void ABC::View() const
{
	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
}

std::ostream & operator<<(ostream & os, const ABC & abc)
{
	abc.View();  // �������õĻ��������Ӧ���������View
	return os;
}

// =============== baseDMA =====================

baseDMA::baseDMA(const char * l, int r) : ABC(l, r)
{
}
// =============== lacksDMA ====================

lacksDMA::lacksDMA(const char * c, const char * l, int r) : ABC (l, r)
{                                                        // �������ĸ��ƹ��캯����д�Ļ����Զ�����, ���ǵ��õ���û�в�����Ĭ�ϵĹ��캯��, �����Ҫ���г�ʼ���Ļ���Ҫ���ϳ�ʼ���б����
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const ABC & rs) : ABC(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const
{
    ABC::View();
    std::cout << "Color: " << color << std::endl;
}

// ================ hasDMA ================

hasDMA::hasDMA(const char * s, const char * l, int r) : ABC(l, r)
{
	style = new char [std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const ABC & rs) : ABC(rs)
{
	style = new char [std::strlen(s) + 1];
	std::strcpy(style, s);
}

// ���ƹ��캯��
hasDMA::hasDMA(const hasDMA & hs) : ABC(hs)  // �����Զ�����baseDMA(const baseDMA &)ʵ�ָ��ƻ���, �����˶�̬
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)  
{
	if (this == &hs)  // ��ֵ��ʱ��, ������Լ������Լ��Ļ�, ֱ�ӷ��ؾͳ���
		return *this;
	ABC::operator=(hs);  // ����������, ����ĸ�������ôʵ�ֵ�!!!!!!!!!!!!!!!
							 // lackDMA��ʹ�õ���Ĭ�ϵĸ�ֵ����, ��Ϊlack��������û���õ���̬�ڴ����, ��Ĭ�ϵĸ�ֵ�������ڸ�ֵ���ಿ�ֵ�ʱ����û���ĸ�ֵ����, ������������ʹ��Ĭ�ϵĸ�ֵ����ʱ���ʵ�
	delete [] style;  // ǧ������˼������
	
	//style = hs.style;   �����jb����????   �����Ĭ�ϵĸ�ֵ����ûʲô������, ����ָ��Ķ��е�ͬһ������, Ȼ����������ͷ���, �ٴ��ͷŵ�ʱ��֪����ô�ͷ���!!!!!!!!!!!!!!!!!
	style = new char [std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);

	return *this;
}

void hasDMA::View() const
{
    ABC::View();
    std::cout << "Style: " << style << std::endl;
}
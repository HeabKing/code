#include "p519�̳��еĶ�̬�ڴ�������Ԫ��������_ͷ�ļ�.h"
#include <cstring>

baseDMA::baseDMA(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
	std::cout << "����baseDMA�Ĺ��췽��\n";
}

baseDMA::baseDMA(const baseDMA & rs)
{  // ���ڳ�ʼ����ʱ���¶��󲻻����Ĭ�Ϲ��캯������ֱ�ӵ���������ƹ��캯��, ��������label��û�б�Ĭ�Ϲ��캯����ʼ��Ϊ"null", �������ﲻ����ֵ���������ͷ�label�Ķ��ڴ��ٽ��и�ֵ
	label = new char [std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;   // ???????????? Ϊʲô����ֱ�ӷ���rs�е�rating���԰�???????????????
}                         // �ѵ��Ǳ���ĳ�Ա����Ҳ���Է������������˽�з���?????

baseDMA::~baseDMA()
{
	delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)// ������Ȼ��ʾ����hasDMA���͵�����, ����ʵ��������hasDMA���͵�, �����������ǲ��ܷ��ʻ���˽�г�Ա��, �����������ý��˻���ĳ�Ա����, ���Ծ���ʹ��˽��������??????????????????????????
{
	if (this == &rs)
		return *this;
	delete [] label;  // �ڽ��и�ֵ֮ǰһ��Ҫ�Ȱ�֮ǰ�Ķ�̬������ڴ��ͷŵ���
	label = new char [std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

// ������Ԫ�����Ķ���
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

lacksDMA::lacksDMA(const char * c, const char * l, int r) : baseDMA (l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : baseDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
	// ���������ʹ�û������Ԫ
	os << (const baseDMA &)ls;  // ���������������ʾ����ת����������ô��?????????????
	os << "Color: " << ls.color << std::endl;
	return os;
}

hasDMA::hasDMA(const char * s, const char * l, int r) : baseDMA(l, r)
{
	style = new char [std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA &rs) : baseDMA(rs)
{
	style = new char [std::strlen(s) + 1];
	std::strcpy(style, s);
}

// ���ƹ��캯��
hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs)  // �����Զ�����baseDMA(const baseDMA &)ʵ�ָ��ƻ���, �����˶�̬
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
	baseDMA::operator=(hs);  // ����������, ����ĸ�������ôʵ�ֵ�!!!!!!!!!!!!!!!
							 // lackDMA��ʹ�õ���Ĭ�ϵĸ�ֵ����, ��Ϊlack��������û���õ���̬�ڴ����, ��Ĭ�ϵĸ�ֵ�������ڸ�ֵ���ಿ�ֵ�ʱ����û���ĸ�ֵ����, ������������ʹ��Ĭ�ϵĸ�ֵ����ʱ���ʵ�
	delete [] style;  // ǧ������˼������
	
	//style = hs.style;   �����jb����????   �����Ĭ�ϵĸ�ֵ����ûʲô������, ����ָ��Ķ��е�ͬһ������, Ȼ����������ͷ���, �ٴ��ͷŵ�ʱ��֪����ô�ͷ���!!!!!!!!!!!!!!!!!
	style = new char [std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);

	return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
	// ���������ʹ�û������Ԫ ��Ԫ���ǳ�Ա����, ���Բ������������������ָ��ʹ���Ǹ���Ԫ����, ����Ҫ��ǿ������ת��, �Ա�ƥ��ԭ�͵�ʱ���ܹ�ѡ����ȷ�ĺ���
	os << (const baseDMA &) hs;  // ����ʵ�ֵĵ��û����operator<<����, �����ǵ��ñ��������
	os << "Style: " << hs.style << std::endl;
	return os;
}
// ��̬�ڴ���������Ҫ���¶���ĺ���: ��������, ���ƺ���, =�����
#ifndef ��̬�ڴ�_��Ԫ_13_7_3
#define ��̬�ڴ�_��Ԫ_13_7_3
#include <iostream>

class baseDMA
{
private:  // label ��ǩ
	char * label;  // Ҫʹ�ù��캯��Ϊ�䶯̬�����ڴ�
	int rating;
public:
	baseDMA(const char * l = "null", int r = 0);  // û�в����Ĺ��캯����Ĭ�Ϲ��캯��, ��ʼ��������ù��캯��, ���������"null"ɾ��, baseDMA a; �ᱨ��, ����дbaseDMA a = baseDMA("hehe");�ǿ��Ե�
	baseDMA(const baseDMA & rs);  // ���ƺ���
	virtual ~baseDMA();  // �����б��̳п��ܵ��඼Ū������������, ���ǽ����˷�һ���ռ��ʱ�����
	baseDMA & operator=(const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs); // ��Ԫ�������
	// ����ʹ����Ԫ��ԭ������Ҫ��ostream������ʱ����˽�������Դﵽ�����Ŀ��!!!!!!
};

// һ���̳���ʹ�ö�̬�ڴ������������û��ʹ�ö�̬�ڴ�����������
class lacksDMA : public baseDMA
{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];  // û��ʹ�ö�̬�ڴ�����һ��ָ���(char *)��ʽ�����ַ�������ѡ�����ַ��������ʽ
public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);  // ��Ԫ�������
};

// ����ʹ���˶�̬�ڴ����, ������Ҳʹ���˵����
class hasDMA : public baseDMA
{
private:
	char * style;  // �ڹ��캯��Ϊ��ʹ�ö�̬�ڴ����
public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const baseDMA & rs);
	hasDMA(const hasDMA & hs);  // ���ƹ��캯��
	virtual ~hasDMA();
	virtual hasDMA & operator=(const hasDMA & rs);  // ��ֵ����
	friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

#endif
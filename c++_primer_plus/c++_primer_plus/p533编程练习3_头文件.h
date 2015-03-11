// ��̬�ڴ���������Ҫ���¶���ĺ���: ��������, ���ƺ���, =�����
#ifndef ��̬�ڴ�_��Ԫ_13_7_3
#define ��̬�ڴ�_��Ԫ_13_7_3
#include <iostream>

class ABC
{
private:
	char * label;
	int rating;
public:
	ABC(const char * l = "NoLabel", int ra = -1);  // Ĭ�Ϲ��캯��
	ABC(const ABC & abc);  // ���ƹ��캯��
	virtual ~ABC() = 0;  // ����������  // ʵ��û��ʲô�������������д��, ���������ɴ��麯��, ������Ϊ�˲��������ɶ���
	virtual ABC & operator*()  { return *this; }
	ABC & operator=(const ABC & abc);  // ��ֵ����  
	virtual void View() const;
	friend std::ostream & operator<<(std::ostream & os, const ABC &);  // �������virtual��=0����ô����   error C2254: ��<<��: ��Ԫ�����ϲ�����ʹ�ô�˵�����������д˵����
	// ������һ�����������
};

class baseDMA : public ABC
{
public:
	//baseDMA(const char * l = "null", int r = 0); // �Զ�����Ĭ�Ϲ��캯��, Ĭ�Ϲ��캯���Զ����û����Ĭ�Ϲ��캯��
	//baseDMA(const baseDMA & rs);  // ���ƺ���  // Ҳ���Զ����û���ĸ��ƹ��캯��
	//~baseDMA();  //����������������Զ�����, ���һ��ඨ�������, �����Ҳ���������
	//baseDMA & operator=(const baseDMA & rs);  // �Զ����ɵĸ�ֵ��������û���ĸ�ֵ����
	baseDMA(const char * l = "NoLabel", int r = 0);
};

// һ���̳���ʹ�ö�̬�ڴ������������û��ʹ�ö�̬�ڴ�����������
class lacksDMA : public ABC
{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];  // û��ʹ�ö�̬�ڴ�����һ��ָ���(char *)��ʽ�����ַ�������ѡ�����ַ��������ʽ
public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const ABC & rs);
	void View() const;
	//friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);  // ��Ԫ�������
};

// ����ʹ���˶�̬�ڴ����, ������Ҳʹ���˵����
class hasDMA : public ABC
{
private:
	char * style;  // �ڹ��캯��Ϊ��ʹ�ö�̬�ڴ����
public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const ABC & rs);
	hasDMA(const hasDMA & hs);  // ���ƹ��캯��
	virtual ~hasDMA();
	virtual hasDMA & operator=(const hasDMA & rs);  // ��ֵ����
	void View() const;
	//friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

#endif
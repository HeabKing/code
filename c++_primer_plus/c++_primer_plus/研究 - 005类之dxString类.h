// p426��ʼ 462����

// c++������Ĭ�����ɵ������Ա����:
// 1. Ĭ�Ϲ��캯��  // û�в�����ȫ������Ĭ�ϲ����Ĺ��캯��
// 2. Ĭ����������
// 3. ���ƹ��캯��  �½�һ�����󲢽����ʼ��Ϊͬ�����ж����ʱ�򽫻��Զ����ø��ƹ��캯��, StringBad(const StringBad &);
			 // 1. ������ֵ���ݶ���  2. �������ض���  3. �����¶��󲢽����ʼ��Ϊͬ��ĳ�������ʱ��  4. ����������ӿ��ܴ�����ʱ���󱣴��м�����ʱ��
// 4. ��ֵ�����
// 5. ��ַ�����

#include <iostream>
#ifndef  dxString_H_
#define  dxString_H_

class dxString
{
private:
	char *		str;
	int			len;
	static int	num_string;
	static const int CINLIM = 80;	// ��̬ ���� ����ֱ�Ӹ�ֵ
public:
	dxString(const char * s);		// ת�����캯��
	dxString();	// Ĭ�Ϲ��캯��
	dxString(const dxString & st);	// ��ȸ��ƹ���ת������
									// 1. ��ʽ��ʼ������
									// 2. Ҳ�����ڰ�ֵ���ݵ�ʱ��, ���¶���������г�ʼ��
									// 3. ���ض���
									// 4. �������������ʱ���󱣴��м�ֵ
	~dxString();

	int length() const {return len;}

	dxString & operator=(const dxString & st);	// ���������char * pch���ͨ���������ʵ�ֵĻ�����Ҫ��pchͨ��ת�����캯��������ʱ����, Ȼ�����ʱ�������ø�����, ̫�鷳��, ��������һ��char * �ĺ������б�Ҫ
	dxString & operator=(const char * pch);
	char		& operator[](int i);
	const char	& operator[](int i) const;

	friend bool operator< (const dxString & st1, const dxString & st2);
	friend bool operator> (const dxString & st1, const dxString & st2);
	friend bool operator==(const dxString & st1, const dxString & st2);
	
	friend std::ostream & operator<<(std::ostream & os, const dxString & st);
	friend std::istream & operator>>(std::istream & is, dxString & st);

		// ��̬��Ա����
	static int HowMany();	// �����в��ü�static
							// ����ͨ��������þ�̬��Ա����(���������������������), ��̬��Ա��������ʹ��thisָ��;
							// ��̬��Ա���������ض����������, ���ֻ��ʹ�þ�̬���ݳ�Ա, �����ܷ���len;
							// ����ͨ����̬��Ա���������༶(classwide)���, �Կ���ĳЩ�ӿڵ���Ϊ;
};

#endif
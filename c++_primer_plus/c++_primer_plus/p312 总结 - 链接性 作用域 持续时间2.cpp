#include <iostream>
using namespace std;

	// ������һ���ļ���warming
extern double warming;
// extern double warming = 0; ����ᵼ�¶��ض���
// double warming; ����ᵼ�¶��ض���
// static double warming = 50;  // ������ᵼ�¶��ض���, ���ǻ����������ӵ�ȫ�ֱ���warming

	// ����һ��ȫ�ֱ���
int i;

	// ����������������ԭ��һ��Ҳ�ǿ��Ե�
	// ��ͺñ���include��һ��ͷ�ļ�, ����Ķ���ֻ�����͵�����, ���ᵼ���ڴ�ķ���

void update(double);
void local();
void local();  // ��ʹ��ͬһ���ļ�������ԭ������Ҳû��, �����������ڴ��ǰ�
//int temp;     // ����Ͳ�����, ��Ϊ�����ǲ����ظ�����, �����ظ�����, Ϊͬһ�����ַ�������ռ䵱Ȼ������
//int temp;
extern double warming; // �����������warming�ǿ��Ե�, �������ᵼ���ڴ�ķ���, �ǰ�
extern double warming;
void local(double);  // ����ֻ��������, ��û�и�������, ���������е�������ʱ��ᱨ��

void update(double dt)
{
	extern double warming;  // �������һ��������, �������ֻ�Ǳ���������ʹ���������ļ��ı���
	warming += dt;
	cout << "��ȫ�ֱ���warming����Ϊ: " << warming << endl;
}

void local(void)
{
	double warming = 0.8;  // ���ｫ������ȫ�ֱ���warming
	cout << "�ֲ�����warming��: " << warming << endl;

		// ʹ�ñ����صı����ķ���

	cout << "ȫ�ֱ���ͨ�����������������Ϊ: " << ::warming << endl;
}